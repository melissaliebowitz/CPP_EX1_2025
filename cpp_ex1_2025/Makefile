#melissaliebowitz@yahoo.com

CXX = clang++-18
CXXFLAGS = -std=c++17 -Wall -g -Iinclude
LDFLAGS = -lstdc++fs -pthread

SRC_D = src
INC_D = include
BUILD_D = build
TEST_D = tests

SRC_FILES = $(SRC_D)/AdjList.cpp $(SRC_D)/Algorithms.cpp $(SRC_D)/graph.cpp $(SRC_D)/minPriorityQueue.cpp $(SRC_D)/queue.cpp $(SRC_D)/stack.cpp $(SRC_D)/unionfind.cpp
MAIN_FILE = $(SRC_D)/main.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
MAIN_OBJ = $(MAIN_FILE:.cpp=.o)

EXEC = $(BUILD_D)/main
TEST_EXEC = $(BUILD_D)/test

.PHONY: all main test valgrind clean

all: main

main: $(OBJ_FILES) $(MAIN_OBJ)
	$(CXX) $^ -o $(EXEC) $(CXXFLAGS) $(LDFLAGS)

test: $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) $(wildcard $(TEST_D)/*.cpp) -o $(TEST_EXEC) $(CXXFLAGS) $(LDFLAGS)
	$(TEST_EXEC)

valgrind: main
	valgrind --leak-check=full --track-origins=yes $(EXEC)

clean:
	rm -f $(OBJ_FILES) $(MAIN_OBJ) $(EXEC) $(TEST_EXEC)
