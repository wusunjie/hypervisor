ifeq ($(ARCH_TYPE), cortex-m4)

CURRENT_DIR:=$(shell pwd)/build

include $(CURRENT_DIR)/cortex-m4/common.mk
ifeq ($(USE_CMSIS), yes)
include $(CURRENT_DIR)/cortex-m4/cmsis.mk
endif

endif
