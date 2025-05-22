FILEPATH?=AlgoExpert/easy/017_middleNode.cpp
NO_INPUT?=no
FILENAME:=$(notdir $(FILEPATH))
OBJ_NAME:=$(patsubst %.cpp,%.o,$(FILENAME))
CPP_CMD:=g++
CURRENT_DIR:= $(dir $(FILEPATH))

GREEN:=\033[0;32m
YELLOW := \033[0;33m
NC:=\033[0m # No Color

# Command directive for g++ compiler in MacOS
ifeq ($(shell uname), Darwin)
	CPP_CMD=g++-13
endif


cpp:
	@( \
		echo "$(GREEN)compiling...$(NC)"; \
		$(CPP_CMD) -std=c++14 $(FILEPATH) -o output/$(OBJ_NAME) || exit 0; \
		echo "$(YELLOW)executing...$(NC)"; \
		if [ "$(NO_INPUT)" = "yes" ]; then \
			output/$(OBJ_NAME); \
		else \
			output/$(OBJ_NAME) < $(CURRENT_DIR)/input.txt; \
		fi \
	)

py:
	@( \
		echo "$(YELLOW)executing...$(NC)"; \
		if [ "$(NO_INPUT)" = "yes" ]; then \
			python3 $(FILEPATH); \
		else \
			python3 $(FILEPATH) < $(CURRENT_DIR)/input.txt; \
		fi \
	)