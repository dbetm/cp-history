CPP_FILEPATH?=AlgoExpert/easy/017_middleNode.cpp
COMPILED_CPP_FILE:=$(notdir $(CPP_FILEPATH))
OBJ_NAME := $(patsubst %.cpp,%.o,$(COMPILED_CPP_FILE))

CURRENT_DIR:= $(dir $(CPP_FILEPATH))

GREEN:=\033[0;32m
YELLOW := \033[0;33m
NC:=\033[0m # No Color

run-cpp:
	@( \
		echo "$(GREEN)compiling...$(NC)"; \
		g++ -std=c++14 $(CPP_FILEPATH) -o output/$(OBJ_NAME) || exit 0; \
		echo "$(YELLOW)executing...$(NC)"; \
		output/$(OBJ_NAME) < $(CURRENT_DIR)/input.txt; \
	)