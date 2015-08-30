
SOURCE_FILES:= \
	$(shell pwd)/device/source/*.c

all_objs:
	$(CC) $(CC_OPTS) $(DRIVER_DEFINES) $(DRIVER_INC_PATH) $(SOURCE_FILES)
	mv *.o $(ROOT_DIR)/objs

clean_objs:
	rm -f *.o
