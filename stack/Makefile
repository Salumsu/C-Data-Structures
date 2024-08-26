# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c11

# Define the target executable
TARGET = stack-test

# Define the source files and object files
SRC = $(wildcard ./*.c)
OBJ = $(SRC:.c=.o)

# Default rule to build the target
$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) && ./$(TARGET)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(TARGET)