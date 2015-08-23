SPECS:=--specs=nosys.specs

ARCH_OPTIONS:=-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=$(USE_FPU_TYPE) -mthumb

CROSS_CC:=arm-none-eabi-gcc

CROSS_AR:=arm-none-eabi-ar

