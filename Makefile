include config.mk

export

$(shell rm -rf $(OBJS_OUTPUT_DIR))
$(shell mkdir $(OBJS_OUTPUT_DIR))

all: build_arch build_libs build_qpc
	$(CROSS_AR) -rs out/platform.a out/*.o
	rm -rf $(OBJS_OUTPUT_DIR)/*.o

build_arch:
	make -C arch
build_libs:
	make -C libs
build_qpc:
	make -C qpc

clean:
	rm -rf $(OBJS_OUTPUT_DIR)
