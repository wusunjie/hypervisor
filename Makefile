ROOT_DIR:=$(shell pwd)

include mk/config.mk

all_objs:
	make -C driver
	make -C boot
	make -C qpc

clean_objs:
	make -C driver clean_objs
	make -C boot clean_objs
	make -C qpc clean_objs
