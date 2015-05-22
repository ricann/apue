#compile related
CC = echo $(notdir $<);gcc
AS = as
LD = echo $(notdir $@);gcc
RM = rm
MAKE = make
MKDIR = mkdir

CC_FLAGS = -c -g -O2 -Wall
LIB_A_FLAGS = -shared
LIB_SO_FLAGS = -shared -fPic
LD_FLAGS =
RM_FLAGS = -f
MKDIR_FLAGS =
