CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g -I include -I json-develop/single_include

TARGET   := Tearoma

SRC_DIRS := src/engine src/systems src/ui
SRCS     := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))

BUILD_DIR := build
OBJS      := $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TARGET).dSYM

.PHONY: all run clean
