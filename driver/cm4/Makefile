
SOURCE_FILES:= \
	$(SUBDIR)/device/source/*.c

INCLUDE_PATH:= \
	-I$(SUBDIR)/include \
	-I$(SUBDIR)/device/include

DEFINES = -DHSE_VALUE=$(CLOCK_FREQ)
ifeq ($(DEVICE_TYPE), stm32f407zg)
DEFINES+=-DSTM32F40_41xxx
endif

DRIVER_INCLUDE_PATH:=$(INCLUDE_PATH)
DRIVER_DEFINES:=$(DEFINES)

export DRIVER_INCLUDE_PATH
export DRIVER_DEFINES

all_objs:
	$(CC) $(CC_OPTS) $(DEFINES) $(INCLUDE_PATH) $(SOURCE_FILES)

clean_objs:
	rm -f *.o
