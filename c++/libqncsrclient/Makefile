###############################################################################
# 
# Generic Makefile 
# Usage: make [build | rebuild | clean | release]
#
###############################################################################

#------------------------------------------------------------------------------
# Include other config file if necessary.
#------------------------------------------------------------------------------
include ./Makefile.def

#------------------------------------------------------------------------------
# Adjust the following if necessary
#------------------------------------------------------------------------------

EXECUTABLE	:= qncsrclient
POSTFIX		:= dll #dll #lib
SLICE_MAKE	:= no # yes or no 是否需要编译slice文件



DEST_EXE 	=  $(PRODUCT_DEST_EXE)
DEST_LIB 	=  $(PRODUCT_DEST_LIB)

INCLUDE_PATH 	:= 	./src \
			./slice\
			./include \
			./lib/log4cppz/include\
			./lib/ice/include

LIB_PATH	:= $(PRODUCT_LIB_PATH) \
			./lib/log4cppz/lib \
			./lib/ice/lib
LIBS 		:=$(PRODUCT_LIBS) log4cppz Ice IceUtil

#------------------------------------------------------------------------------
# Now alter any implicit rules' variables if you like, e.g.:
#------------------------------------------------------------------------------
CXXFLAGS 	:= $(PRODUCT_CXXFLAGS) -Wall

#------------------------------------------------------------------------------
# Include Makefile rule
#------------------------------------------------------------------------------
include ./Makefile.rul

#------------------------------------------------------------------------------
# End of Makefile 
#------------------------------------------------------------------------------
