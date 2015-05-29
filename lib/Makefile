.PHONY: all clean
.SILENT:


include make.h

all: libunp.a libunp.so

libunp.a: ${LIB_OBJ_DIR}/libunp.o
	$(AR) $(LIB_A_FLAGS) $@ $<

libunp.so: ${LIB_OBJ_DIR}/libunp.o
	$(LD) $(LIB_SO_FLAGS) -o $@ $<

${LIB_OBJ_DIR}/libunp.o: ${LIB_SRC_DIR}/libunp.c
	$(CC) $(CC_FLAGS) ${LIB_INC} -o $@ $<


clean:
	$(RM) ${LIB_OBJ_DIR}/*.o
	$(RM) libunp.a
	$(RM) libunp.so
