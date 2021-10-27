CC=gcc
CFLAGS=-g -pedantic -Wall -std=c99
SRCS=$(wildcard src/*.c)
OBJS=$(patsubst src/*.c, obj/*.o, $(SRCS))
BIN=table.exe

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm obj/*.o $(BIN)