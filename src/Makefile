APP_NAME = matrix
SRC = matrix.cpp
BIN_DIR = ../usr/local/bin

CXX = g++
CXXFLAGS = -Wall -Werror -std=c++17

all: $(APP_NAME)

$(APP_NAME): $(SRC)
	@echo "Компиляция программы..."
	$(CXX) $(CXXFLAGS) $^ -o $@
	mkdir -p $(BIN_DIR)
	mv $@ $(BIN_DIR)/
	@echo "Compilation complete"

clean:
	@echo "Очистка..."
	rm -f $(BIN_DIR)/$(APP_NAME)

help:
	@echo "Доступные цели:"
	@echo "  all        — сборка программы"
	@echo "  matrix     — компиляция"
	@echo "  clean      — очистка"
	@echo "  help       — справка"

.PHONY: all clean help




