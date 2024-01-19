FILEPATH?=AlgoExpert/easy/017_middleNode.cpp
FILENAME:=$(notdir $(FILEPATH))
OBJ_NAME := $(patsubst %.cpp,%.o,$(FILENAME))

CURRENT_DIR:= $(dir $(FILEPATH))

GREEN:=\033[0;32m
YELLOW := \033[0;33m
NC:=\033[0m # No Color

cpp:
	@( \
		echo "$(GREEN)compiling...$(NC)"; \
		g++ -std=c++14 $(FILEPATH) -o output/$(OBJ_NAME) || exit 0; \
		echo "$(YELLOW)executing...$(NC)"; \
		output/$(OBJ_NAME) < $(CURRENT_DIR)/input.txt; \
	)

py:
	@( \
		echo "$(YELLOW)executing...$(NC)"; \
		python3 $(FILEPATH) < $(CURRENT_DIR)/input.txt; \
	)