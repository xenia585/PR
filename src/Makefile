APP_NAME = matrix_check
SRC_FILE = main.cpp
BIN_DIR = ../usr/local/bin

all: build

build:
	@echo "Компиляция программы..."
	@mkdir -p $(BIN_DIR)
	g++ -std=c++17 -O2 -Wall $(SRC_FILE) -o $(BIN_DIR)/$(APP_NAME)
	@echo "Компиляция завершена!"

clean:
	@echo "Очистка..."
	@rm -f $(BIN_DIR)/$(APP_NAME)

