include config.mk

export

all: build_arch build_libs build_qpc

build_arch:
	make -C arch
build_libs:
	make -C libs
build_qpc:
	make -C qpc

clean:
	make -C arch clean
	make -C libs clean
	make -C qpc clean
