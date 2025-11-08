# Makefile for count-words program (Task 0)

CC = gcc
CFLAGS = -m32 -g -Wall -Wextra
TARGET = count-words

all: $(TARGET)

$(TARGET): count-words.c
	$(CC) $(CFLAGS) -o $(TARGET) count-words.c

clean:
	rm -f $(TARGET)

.PHONY: all clean

