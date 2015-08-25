ifeq ($(DEVICE_TYPE), stm32f407zg)
PORT_DIR:=$(shell pwd)/ports/cm4
CC:=arm-none-eabi-gcc -c
AS:=arm-none-eabi-as
CC_OPTS:=-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=$(USE_FPU_TYPE) -mthumb
AS_OPTS:=-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=$(USE_FPU_TYPE) -mthumb
else
$(error this DEVICE_TYPE isn't supported now.)
endif

SOURCE_FILES:= \
	$(shell pwd)/source/*.c

ASM_FILES:= \
	$(PORT_DIR)/*.s

INCLUDE_PATH:= \
	-I$(shell pwd)/include \
	-I$(PORT_DIR) \
	$(DRIVER_INCLUDE_PATH)

DEFINES:= \
	-DQ_SPY \
	$(DRIVER_DEFINES)

all_objs:
	$(CC) $(CC_OPTS) $(DEFINES) $(INCLUDE_PATH) $(SOURCE_FILES)
	$(AS) $(AS_OPTS) $(ASM_FILES) -o qk_port.o

clean_objs:
	rm -f *.o
