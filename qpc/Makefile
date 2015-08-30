ifeq ($(DEVICE_TYPE), stm32f407zg)
PORT_DIR:=$(shell pwd)/ports/cm4
CC:=arm-none-eabi-gcc -c
AS:=arm-none-eabi-as
CC_OPTS:=-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=$(USE_FPU_TYPE) -mthumb
AS_OPTS:=-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=$(USE_FPU_TYPE) -mthumb
else
$(error this DEVICE_TYPE isn't supported now.)
endif

SRC_QS_FILES:= \
	$(shell pwd)/source/qs_64bit.c \
	$(shell pwd)/source/qs.c \
	$(shell pwd)/source/qs_fp.c

SRC_QK_FILES:= \
	$(shell pwd)/source/qk.c \
	$(shell pwd)/source/qk_mutex.c \
	$(PORT_DIR)/qk/*.c

SRC_QV_FILES:=$(shell pwd)/source/qv.c

SRC_COMMON_FILES:= \
	$(shell pwd)/source/qep_hsm.c \
	$(shell pwd)/source/qep_msm.c \
	$(shell pwd)/source/qf_act.c \
	$(shell pwd)/source/qf_actq.c \
	$(shell pwd)/source/qf_defer.c \
	$(shell pwd)/source/qf_dyn.c \
	$(shell pwd)/source/qf_mem.c \
	$(shell pwd)/source/qf_qact.c \
	$(shell pwd)/source/qf_ps.c \
	$(shell pwd)/source/qf_qeq.c \
	$(shell pwd)/source/qf_qmact.c \
	$(shell pwd)/source/qf_time.c

SOURCE_FILES:= \
	$(SRC_COMMON_FILES) \
	$(SRC_QK_FILES)

ASM_FILES:= \
	$(PORT_DIR)/*.s

INCLUDE_PATH:= \
	-I$(shell pwd)/include \
	-I$(PORT_DIR) \
	$(DRIVER_INC_PATH)

DEFINES:= \
	$(DRIVER_DEFINES)

all_objs:
	$(CC) $(CC_OPTS) $(DEFINES) -DQ_NASSERT $(INCLUDE_PATH) $(SOURCE_FILES)
	$(AS) $(AS_OPTS) $(ASM_FILES) -o qk_port.o
	mv *.o $(ROOT_DIR)/objs

