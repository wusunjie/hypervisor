ifeq ($(DEVICE_TYPE), stm32f407zg)
SUBDIR:=cm4
AS:=arm-none-eabi-as
AS_OPTS:=-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=$(USE_FPU_TYPE) -mthumb
else
$(error this DEVICE_TYPE isn't supported now.)
endif

all_objs:
	$(AS) $(AS_OPTS) $(SUBDIR)/*.s -o $(notdir $(shell pwd)).o

clean_objs:
	rm -f *.o
