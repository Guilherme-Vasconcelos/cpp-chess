EXE := cpp_chess
TESTS_EXE := cpp_chess_tests
EXAMPLE_EXE := cpp_chess_example

SRC_DIR := src
OBJ_DIR := bin
EXAMPLES_DIR := examples
TESTS_DIR := tests

CXXFLAGS=-g

CPPFLAGS := -std=c++11 -Wall -pedantic -I$(SRC_DIR)/include
TEST_CPPFLAGS := -std=c++11 -Wall -pedantic -I$(TESTS_DIR)/include -I$(SRC_DIR)/include

SRC := $(wildcard $(SRC_DIR)/*.cpp)
TESTS := $(wildcard $(TESTS_DIR)/*.cpp)
EXAMPLES := $(wildcard $(EXAMPLES_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CPPFLAGS) $^ -o $(OBJ_DIR)/$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

$(OBJ_DIR):
	mkdir $@

clean:
	$(RM) -r $(OBJ_DIR)

test:
	$(CXX) $(TEST_CPPFLAGS) $(SRC) $(TESTS) -o $(OBJ_DIR)/$(TESTS_EXE)

example:
	$(CXX) $(CPPFLAGS) $(SRC) $(EXAMPLES) -o $(OBJ_DIR)/$(EXAMPLE_EXE)

.PHONY: all clean
