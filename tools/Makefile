CC := gcc
CFLAGS := -I . -Wall -Wextra -pedantic -std=c99 -O3 -s
PROGRAMS := n64cksum

n64cksum_SOURCES := n64cksum.c libmio0.c libsm64.c utils.c

all: $(PROGRAMS)

clean:
	$(RM) $(PROGRAMS)

define COMPILE
$(1): $($1_SOURCES)
	$(CC) $(CFLAGS) $($1_CFLAGS) $$^ -lm -o $$@
endef

$(foreach p,$(PROGRAMS),$(eval $(call COMPILE,$(p))))
