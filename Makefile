### Build Options ###

# Override these options in settings.mk or with `make SETTING=value'.

BASEROM = baserom.u.z64
TARGET = marioparty3
COMPARE = 1
NON_MATCHING = 0

# Microcode
GRUCODE_CFLAGS := -DF3DEX_GBI_2
GRUCODE_ASFLAGS := --defsym F3DEX_GBI_2=1

# Fail early if baserom does not exist
ifeq ($(wildcard $(BASEROM)),)
$(error Baserom `$(BASEROM)' not found.)
endif

# NON_MATCHING=1 implies COMPARE=0
ifeq ($(NON_MATCHING),1)
override COMPARE=0
endif


### Output ###

BUILD_DIR := build
ROM := $(BUILD_DIR)/$(TARGET).z64
ELF := $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT := $(TARGET).ld
LD_MAP := $(BUILD_DIR)/$(TARGET).map


### Tools ###

PYTHON := python3
N64CKSUM := tools/n64cksum
SPLAT_YAML := splat.yaml
SPLAT = $(PYTHON) tools/n64splat/split.py $(BASEROM) $(SPLAT_YAML) .
EMULATOR = mupen64plus
SHA1SUM = sha1sum


### Compiler Options ###

CROSS := mips-linux-gnu-
AS := $(CROSS)as
OLD_AS := tools/marioparty-binutils-2.7-as
CC := tools/mips-cc1
CPP := cpp -P
LD := $(CROSS)ld
OBJCOPY := $(CROSS)objcopy

CFLAGSCOMMON = -G 0 -quiet -mcpu=r4300 -mips2

ASFLAGS    := -G 0 -I include -mips3 -mabi=32 $(GRUCODE_ASFLAGS)
OLDASFLAGS := -G 0 -I include -mips2 $(GRUCODE_ASFLAGS)
CFLAGS     := -O1 $(CFLAGSCOMMON)
LDFLAGS    := -T undefined_syms.txt -T undefined_funcs.txt -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(LD_MAP) --no-check-sections

# Check code syntax with host compiler
CC_CHECK := gcc -fsyntax-only -fsigned-char -nostdinc -fno-builtin -I include -I $(BUILD_DIR)/include -I src\
	-std=gnu90 -Wall -Wextra -Wno-format-security -Wno-unused-parameter -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast $(GRUCODE_CFLAGS)


### Sources ###

# Directories containing source files
SRC_DIRS := src src/libultra src/libultra/os src/overlays src/overlays/board_chillywaters
ASM_DIRS := asm asm/overlays
DATA_DIRS := bin bin/overlays

# Source code files
C_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
DATA_FILES := $(foreach dir,$(DATA_DIRS),$(wildcard $(dir)/*.bin))

# Object files
O_FILES := $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
           $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
           $(foreach file,$(DATA_FILES),$(BUILD_DIR)/$(file:.bin=.o)) \

### Targets ###

build/src/libultra/os/%.o: CFLAGS := -O2 $(CFLAGSCOMMON)

clean:
	rm -rf $(BUILD_DIR)

clean-all:
	rm -rf $(BUILD_DIR) asm bin

setup: clean submodules split
	make -C tools

submodules:
	git submodule update --init --recursive

split:
	rm -rf bin asm
	$(SPLAT)
	sed -i 's/\.L800CD1A0/D_800CD1A0/g' asm/code_824C0.s

test: $(ROM)
	$(EMULATOR) $<

$(BUILD_DIR):
	mkdir $(BUILD_DIR) $(addprefix $(BUILD_DIR)/,$(SRC_DIRS) $(ASM_DIRS) $(DATA_DIRS))

$(BUILD_DIR)/$(LD_SCRIPT): $(LD_SCRIPT) $(BUILD_DIR)
	@mkdir -p $(shell dirname $@)
	$(CPP) -DBUILD_DIR=$(BUILD_DIR) -o $@ $<

# Pre-process .c files with the modern cpp.
$(BUILD_DIR)/%.i: %.c $(BUILD_DIR)
	@$(CC_CHECK) -MMD -MP -MT $@ -MF $@.d $<
	$(CPP) -MMD -MP -MT $@ -MF $@.d -I include/ -o $@ $<

# Go from .i to .s...
$(BUILD_DIR)/src/%.s: $(BUILD_DIR)/src/%.i
	$(CC) $(CFLAGS) -o $@ $<

# Run a separate assembler for src and asm .s files.
$(BUILD_DIR)/asm/%.o: asm/%.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/src/%.o: $(BUILD_DIR)/src/%.s
	$(OLD_AS) $(OLDASFLAGS) -o $@ $<

# Create .o files from .bin files.
$(BUILD_DIR)/%.o: %.bin
	$(LD) -r -b binary -o $@ $<

# Continue the rest of the build...
$(BUILD_DIR)/$(TARGET).elf: $(BUILD_DIR)/$(LD_SCRIPT) $(O_FILES)
	$(LD) $(LDFLAGS) -o $@ $(O_FILES) $(LIBS)

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) $< $@ -O binary

$(ROM): $(BUILD_DIR)/$(TARGET).bin
	@cp $< $@
	$(N64CKSUM) $< $@
ifeq ($(COMPARE),1)
	@$(SHA1SUM) -c $(TARGET).sha1 || (echo 'The build succeeded, but did not match the base ROM. This is expected if you are making changes to the game. To skip this check, use "make COMPARE=0".' && false)
endif


### Make Settings ###

.PHONY: clean test setup submodules split $(ROM)
.DELETE_ON_ERROR:
.SECONDARY:
.PRECIOUS: $(ROM)
.DEFAULT_GOAL := $(ROM)

# Remove built-in implicit rules to improve performance
MAKEFLAGS += --no-builtin-rules

# Fail targets if any command in the pipe exits with error
SHELL = /bin/bash -e -o pipefail
