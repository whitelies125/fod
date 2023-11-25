CXX := g++

TARGET := fod

BUILD_DIR := ./build
SRC_DIR := ./src

SRC_CXX := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_CXX := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o,$(SRC_CXX))
# 可简写为
# OBJ_CXX := $(SRC_CXX:$(SRC_DIR)%.cpp=$(BUILD_DIR)/%.o)

CXX_FLAGS := -std=c++20 -Wall

# $^ : 比 target 新的所有 prerequisites
$(BUILD_DIR)/$(TARGET) : $(OBJ_CXX)
	$(CXX) -o $@ $^
# $@ : target
# $^ : prerequisites 中的第一个 prerequisite
$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) -o $@ -c $< $(CXX_FLAGS)

.PHONY: clean
RM := del
clean:
	$(RM) *.o
	$(RM) *.exe
