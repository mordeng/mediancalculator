.PHONY: deploy test clean
 
INCLUDE_DIR=../include
CATCH2_DIR=../catch2
TEST_DIR=../tests
CPP_FLAGS=-std=c++11 -Wall
BUILD_PATH = ../build

SRC_PATH=../src/
SRC_EXT= cpp
BIN_NAME=run_test

INCLUDES=\
	-I$(INCLUDE_DIR)\
	-I$(CATCH2_DIR)\
	-I$(TEST_DIR)
 
SRCS=\
	$(TEST_DIR)/default.cpp\
	$(TEST_DIR)/test1.cpp
 
OBJS=$(SRCS:.cpp=.o)
test: $(OBJS)
	@g++ $(CPP_FLAGS) $(INCLUDES) -o $(BIN_NAME) $(OBJS) $(TEST_SRC)
	@./run_test

	
clean:
	@echo "Deleting $(BIN_NAME) symlink"
	@$(RM) $(BIN_NAME)
	@$(RM) $(OBJS)



%.o : %.cpp
	g++ $(CPP_FLAGS) $(INCLUDES) -c $< -o $@
