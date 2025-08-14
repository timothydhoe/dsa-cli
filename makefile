# Simple Makefile for DSA-CLI

CC = gcc
CFLAGS = -std=c11 -Wall

TARGET = dsa
SOURCES = main.c algorithms.c helpers.c structures.c style.c tutorial.c config.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

install: $(TARGET)
	sudo cp $(TARGET) /usr/local/bin/

.PHONY: all clean install