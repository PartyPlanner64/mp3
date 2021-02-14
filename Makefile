### Build Options ###

# Override these options in settings.mk or with `make SETTING=value'.

BASEROM = baserom.u.z64
TARGET = marioparty3
COMPARE = 1
NON_MATCHING = 0
CHECK = 0

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
LDFLAGS    := -T undefined_syms.txt -T undefined_funcs.txt -T undefined_funcs_auto.txt -T undefined_syms_auto.txt -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(LD_MAP) --no-check-sections

# Check code syntax with host compiler
CC_CHECK := gcc -fsyntax-only -fsigned-char -nostdinc -fno-builtin -I include -I $(BUILD_DIR)/include -I src\
	-D CC_CHECK\
	-std=gnu90 -Wall -Wextra -Wno-format-security -Wno-unused-parameter -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast $(GRUCODE_CFLAGS)
ifneq ($(CHECK),1)
CC_CHECK += -w
endif

### Sources ###

# Object files
OBJECTS = $(subst BUILD_DIR, $(BUILD_DIR), $(shell grep -E 'BUILD_DIR.+\.o' marioparty3.ld -o))

### Targets ###

build/src/libultra/os/%.o: CFLAGS := -O2 $(CFLAGSCOMMON)
build/src/libultra/libc/%.o: CFLAGS := -O2 $(CFLAGSCOMMON)
build/src/lib/%.o: CFLAGS := -O2 $(CFLAGSCOMMON)

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

$(BUILD_DIR)/$(LD_SCRIPT): $(LD_SCRIPT)
	@mkdir -p $(shell dirname $@)
	$(CPP) -DBUILD_DIR=$(BUILD_DIR) -o $@ $<

include/ld_addrs.h: $(BUILD_DIR)/$(LD_SCRIPT)
	grep -E "[^ .]+ =" $< -o | sed 's/^/extern void */; s/ =/;/' > $@

# Pre-process .c files with the modern cpp.
$(BUILD_DIR)/src/%.i: src/%.c include/ld_addrs.h
	@mkdir -p $(shell dirname $@)
	@$(CC_CHECK) -MMD -MP -MT $@ -MF $@.d $<
	$(CPP) -MMD -MP -MT $@ -MF $@.d -I include/ -o $@ $<

# Go from .i to .s...
$(BUILD_DIR)/src/%.s: $(BUILD_DIR)/src/%.i
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -o $@ $<

# Run a separate assembler for src and asm .s files.
$(BUILD_DIR)/src/%.c.o: $(BUILD_DIR)/src/%.s
	@mkdir -p $(shell dirname $@)
	$(OLD_AS) $(OLDASFLAGS) -o $@ $<

$(BUILD_DIR)/asm/%.s.o: asm/%.s
	@mkdir -p $(shell dirname $@)
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/data/%.data.o: asm/data/%.data.s
	@mkdir -p $(shell dirname $@)
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/rodata/%.rodata.o: asm/data/%.rodata.s
	@mkdir -p $(shell dirname $@)
	$(AS) $(ASFLAGS) -o $@ $<

# Create .o files from .bin files.
$(BUILD_DIR)/%.bin.o: %.bin
	@mkdir -p $(shell dirname $@)
	$(LD) -r -b binary -o $@ $<

# Continue the rest of the build...
$(BUILD_DIR)/$(TARGET).elf: $(BUILD_DIR)/$(LD_SCRIPT) $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@

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
