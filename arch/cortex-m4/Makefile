CORTEX_M4_INC:=-I$(shell pwd)/include
ifeq ($(DEVICE_TYPE), stm32f4xx)
CORTEX_M4_SUBDIR:=stm32f4xx
CORTEX_M4_INC+=-I$(shell pwd)/include/stm32f4xx
endif

export CORTEX_M4_INC

all:
	make -C $(CORTEX_M4_SUBDIR)

clean:
	make -C $(CORTEX_M4_SUBDIR) clean
