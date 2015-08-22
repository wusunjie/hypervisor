QPC_INC:=-Iinclude

ifeq ($(ARCH_TYPE), cortex-m4)
QPC_PORT_SUBDIR:=ports/cortex-m4
QPC_INC+=-I$(QPC_PORT_SUBDIR)
ifeq ($(USE_FPU_TYPE), hard)
CFLAGS:=-D__PRESENT_FPU
CFLAGS+=-DQ_SPY
endif
endif

all:
	$(CROSS_CC) $(SPECS) $(ARCH_OPTIONS) $(CFLAGS) -S $(QPC_PORT_SUBDIR)/*.s
	$(CROSS_CC) $(SPECS) $(ARCH_OPTIONS) $(QPC_INC) $(CFLAGS) -c source/*.c

clean:
	rm -f *.o
