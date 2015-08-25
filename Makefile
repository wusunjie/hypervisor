ROOT_DIR:=$(shell pwd)

include mk/config.mk

all_objs:
	make -C boot
