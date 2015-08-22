ifeq ($(LIBC_IMPL), newlib)
COMPILER_SUBDIR:=newlib
endif

all:
	$(CROSS_CC) $(SPECS) $(ARCH_OPTIONS) -c newlib/*.c

clean:
	rm -f *.o
