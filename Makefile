
CC = gcc
CFLAGS = -Wall -Wextra -O2 -ILibrary


SRC_DIR = .
LIB_DIR = Library
OBJ_DIR = build\obj
BIN_DIR = build\bin


SRC = $(SRC_DIR)/main.c $(LIB_DIR)/Konversi.c


OBJ = $(OBJ_DIR)/main.o $(OBJ_DIR)/Konversi.o


TARGET = $(BIN_DIR)/program.exe


all: $(TARGET)


$(OBJ_DIR):
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

$(BIN_DIR):
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)


$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/Konversi.o: $(LIB_DIR)/Konversi.c $(LIB_DIR)/Konversi.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $(OBJ) -o $(TARGET)


run: all
	$(TARGET)


clean:
	if exist build rmdir /s /q build

.PHONY: all clean run
