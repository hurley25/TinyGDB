#!Makefile

PROGRAM = TinyGDB

C_SOURCES = $(shell find . -name "*.c")
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

CC = gcc

C_FLAGS = -c -Wall -Wextra -std=c99 -g -I.

all: $(C_OBJECTS) 
	@echo link ...
	$(CC) $(C_OBJECTS) -lm -o $(PROGRAM)

.c.o:
	@echo compiler $< ...
	$(CC) $(C_FLAGS) $< -o $@

.PHONY:clean
clean:
	$(RM) $(C_OBJECTS) $(PROGRAM)

