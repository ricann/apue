.PHONY: all clean

include ../make.h
include make.h


$(LIB_TARGET): $(LIB_OBJ)
	$(AR) $(LIB_A_FLAGS) $@ $^

#define compile rules
$(LIB_OBJ_DIR)/%.o: $(LIB_SRC_DIR)/%.c
	$(CC) $(LIB_CFLAGS) $(LIB_INC) $< -o $@

ifneq ($(MAKECMDGOALS), clean)
sinclude $(LIB_DEP)
endif

$(LIB_OBJ_DIR)/%.dep: $(LIB_SRC_DIR)/%.c
	@set -e ; \
	$(RM) -fr $@.tmp ; \
	$(CC_NO_ECHO) $(LIB_CFLAGS) $(LIB_INC) -E -MM $(filter %.c, $^) > $@.tmp ; \
	sed 's,\($*\)\.o[ :]*,$(LIB_OBJ_DIR)/\1.o $@: ,g' < $@.tmp > $@ ; \
	$(RM) -fr $@.tmp

clean:
	@echo "Cleaning object files"
	$(RM) -f $(LIB_OBJ_DIR)/*.o
	$(RM) -f $(LIB_OBJ_DIR)/*.dep
	$(RM) -f $(LIB_TARGET)

print:
	@echo LIB_TARGET=${LIB_TARGET}
	@echo LIB_INC_DIR=${LIB_INC_DIR}
	@echo LIB_SRC_DIR=${LIB_SRC_DIR}
	@echo LIB_OBJ_DIR=${LIB_OBJ_DIR}
	@echo _LIB_OBJ_DIR=${_LIB_OBJ_DIR}
	@echo LIB_DIRS=${LIB_DIRS}
	@echo LIB_RMS=${LIB_RMS}
	@echo LIB_SRC=${LIB_SRC}
	@echo LIB_OBJ=${LIB_OBJ}
	@echo LIB_DEP=${LIB_DEP}
	@echo LIB_INC=${LIB_INC}
	@echo LIB_CFLAGS=${LIB_CFLAGS}
