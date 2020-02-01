# Compiled binaries
EXE := cpp_chess.out
TESTS_EXE := cpp_chess_tests.out
EXAMPLE_EXE := cpp_chess_example.out

SRC_DIR := src
OBJ_DIR := obj
EXAMPLES_DIR := examples
TESTS_DIR := tests

# g++ compilation flags
CFLAGS := -std=c++11 -Wall -pedantic

# Header files to include for compiling library
INCLUDE := -Iinclude

# Link source files in their respective directories
SRC := $(wildcard $(SRC_DIR)/*.cpp)
TESTS := $(wildcard $(TESTS_DIR)/*.cpp)
EXAMPLES := $(wildcard $(EXAMPLES_DIR)/*.cpp)

# All '.o' files in 'obj' directory
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(EXAMPLE_EXE)

# Compile example in 'examples' directory
$(EXAMPLE_EXE): $(OBJ)
	$(CXX) $(INCLUDE) $(EXAMPLES) $^ -o $@

# Compile '.o' files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(INCLUDE) $(CFLAGS) -c $< -o $@

# Create directory for '.o' files
$(OBJ_DIR):
	mkdir $@

# Compile if needed, then run example file
example: $(EXAMPLE_EXE)
	./$(EXAMPLE_EXE)

# Clean build objects and compiled files
clean:
	$(RM) -r $(OBJ_DIR) *.out

# Compile an run tests
test: $(OBJ)
	$(CXX) $(CPPFLAGS) $(INCLUDE) $(SRC) $(TESTS) -o $(TESTS_EXE)
	./$(TESTS_EXE)

.PHONY: all clean
