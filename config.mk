ARCH_TYPE:=cortex-m4
DEVICE_TYPE:=stm32f4xx
USE_CMSIS:=yes
USE_STDPERIPH:=yes
LIBC_IMPL:=newlib
USE_FPU_TYPE:=hard

OBJS_OUTPUT_DIR:=$(shell pwd)/out

include build/arch.mk
