ARCH_TYPE:=cortex-m4
DEVICE_TYPE:=stm32f4xx
USE_CMSIS:=yes
USE_STDPERIPH:=yes
LIBC_IMPL:=newlib
USE_FPU_TYPE:=hard

include build/arch.mk
