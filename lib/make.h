LIB_TARGET = $(LIB_BASE)/libunp.a

LIB_INC_DIR		= $(LIB_BASE)/inc
LIB_SRC_DIR		= $(LIB_BASE)/src
LIB_OBJ_DIR		= $(LIB_BASE)/obj

LIB_DIRS		= $(LIB_INC_DIR)  $(LIB_SRC_DIR)  $(LIB_OBJ_DIR)
LIB_SRC		= $(wildcard $(LIB_SRC_DIR)/*.c)

LIB_OBJ		= $(LIB_SRC:.c=.o)
LIB_OBJ		:= $(filter %.o, $(LIB_OBJ))
LIB_OBJ		:= $(patsubst $(LIB_SRC_DIR)/%, $(LIB_OBJ_DIR)/%, $(LIB_OBJ))

LIB_DEP		= $(LIB_SRC:.c=.dep)
LIB_DEP		:= $(filter %.dep, $(LIB_DEP))
LIB_DEP		:= $(patsubst $(LIB_SRC_DIR)/%, $(LIB_OBJ_DIR)/%, $(LIB_DEP))

LIB_INC		= -I$(LIB_INC_DIR)

LIB_CFLAGS	= $(CC_FLAGS)
