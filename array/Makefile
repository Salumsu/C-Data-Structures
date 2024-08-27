# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c11

# Define the target executable
TARGET = array-test

# Define the source files and object files
SRC = $(wildcard ./*.c)
OBJ = $(SRC:.c=.o)

# int-helpers source and object files
INTHELPERS_DIR = ../utils/int-helpers/
INTHELPERS_SRC = $(INTHELPERS_DIR)int-helpers.c
INTHELPERS_OBJ = $(INTHELPERS_SRC:.c=.o)

# Default rule to build the target
$(TARGET): $(OBJ) $(INTHELPERS_OBJ)
	$(CC) -o $@ $(OBJ) $(INTHELPERS_OBJ) && ./$(TARGET)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile int-helpers.c to int-helpers.o
$(INTHELPERS_OBJ): $(INTHELPERS_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(INTHELPERS_OBJ) $(TARGET)
