ROOT_DIR:=$(shell pwd)

include mk/config.mk

all_objs:
	$(shell mkdir -p objs)
	make -C driver
	make -C boot
	make -C qpc

clean_objs:
	rm -rf objs
