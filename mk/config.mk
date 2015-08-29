DEVICE_TYPE:=stm32f407zg
USE_FPU_TYPE:=hard
CLOCK_FREQ:=8000000

TARGET_LAYOUT:=direct

ifeq ($(DEVICE_TYPE), stm32f407zg)
DRIVER_INC_PATH:= \
	-I$(shell pwd)/driver/cm4/include \
	-I$(shell pwd)/driver/cm4/device/include
DRIVER_DEFINES:= \
	-DSTM32F40_41xxx \
	-DHSE_VALUE=$(CLOCK_FREQ)
endif

export
