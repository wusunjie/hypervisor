ifeq ($(DEVICE_TYPE), stm32f407zg)
SUBDIR:=$(shell pwd)/cm4
CC:=arm-none-eabi-gcc -c
CC_OPTS:=-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=$(USE_FPU_TYPE) -mthumb
else
$(error this DEVICE_TYPE isn't supported now.)
endif

export CC
export CC_OPTS

all_objs:
	make -C $(SUBDIR)

clean_objs:
	make -C $(SUBDIR) clean_objs
