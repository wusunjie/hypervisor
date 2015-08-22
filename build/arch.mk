ifeq ($(ARCH_TYPE), cortex-m4)

include cortex-m4/common.mk
ifeq ($(USE_CMSIS), yes)
include cortex-m4/cmsis.mk
endif

include cortex-m4/devices.mk


