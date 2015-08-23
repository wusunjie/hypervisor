ifeq ($(DEVICE_TYPE), stm32f4xx)
CFLAGS:=-DSTM32F40_41xxx
ifeq ($(USE_STDPERIPH), yes)
CFLAGS+=-DUSE_STDPERIPH_DRIVER
STDPERIPH_SRC:=stdperiph/stm32f4xx_adc.c \
stdperiph/stm32f4xx_crc.c \
stdperiph/stm32f4xx_dbgmcu.c \
stdperiph/stm32f4xx_dma.c \
stdperiph/stm32f4xx_exti.c \
stdperiph/stm32f4xx_flash.c \
stdperiph/stm32f4xx_gpio.c \
stdperiph/stm32f4xx_i2c.c \
stdperiph/stm32f4xx_iwdg.c \
stdperiph/stm32f4xx_pwr.c \
stdperiph/stm32f4xx_rcc.c \
stdperiph/stm32f4xx_rtc.c \
stdperiph/stm32f4xx_sdio.c \
stdperiph/stm32f4xx_spi.c \
stdperiph/stm32f4xx_syscfg.c \
stdperiph/stm32f4xx_tim.c \
stdperiph/stm32f4xx_usart.c \
stdperiph/stm32f4xx_wwdg.c \
stdperiph/misc.c \
stdperiph/stm32f4xx_cryp.c \
stdperiph/stm32f4xx_hash.c \
stdperiph/stm32f4xx_rng.c \
stdperiph/stm32f4xx_can.c \
stdperiph/stm32f4xx_dac.c \
stdperiph/stm32f4xx_dcmi.c \
stdperiph/stm32f4xx_fsmc.c
endif
endif

all:
ifeq ($(USE_CMSIS), yes)
	$(CROSS_CC) $(SPECS) $(ARCH_OPTIONS) $(CFLAGS) $(CORTEX_M4_INC) -c device/*.c
	mv $(shell pwd)/*.o $(OBJS_OUTPUT_DIR)
ifeq ($(USE_STDPERIPH), yes)
	$(CROSS_CC) $(SPECS) $(ARCH_OPTIONS) $(CFLAGS) $(CORTEX_M4_INC) -c $(STDPERIPH_SRC)
	mv $(shell pwd)/*.o $(OBJS_OUTPUT_DIR)
endif
endif
