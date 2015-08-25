ifeq ($(DEVICE_TYPE), stm32f407zg)
SUBDIR:=cm4
CC:=arm-none-eabi-gcc -c
CC_OPTS:=-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=$(USE_FPU_TYPE)
endif

all_objs:
	$(CC) $(CC_OPTS) $(SUBDIR)/*.s
