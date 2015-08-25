ifeq ($(DEVICE_TYPE), stm32f407zg)
SUBDIR:=$(shell pwd)/cm4
CC:=arm-none-eabi-gcc -c
AS_OPTS:=-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=$(USE_FPU_TYPE)
DEFINES:=-DSTM32F40_41xxx
endif

export

all_objs:
	make -C $(SUBDIR)

clean_objs:
	make -C $(SUBDIR) clean_objs
