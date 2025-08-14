# 🧟 Nightmare Makefile – Kitbuild Compilation Ritual

CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude
SRC = $(wildcard src/**/*.c) $(wildcard main/*.c)
OBJ = $(patsubst %.c,build/%.o,$(SRC))
BIN = bin/kitbuild

# Default ritual
all: $(BIN)

# Link objects into binary
$(BIN): $(OBJ)
    @mkdir -p bin
    $(CC) $(OBJ) -o $(BIN)
    @echo "🧙‍♂️ Linked binary: $(BIN)"

# Compile each source file into object
build/%.o: %.c
    @mkdir -p $(dir $@)
    $(CC) $(CFLAGS) -c $< -o $@
    @echo "⚙️ Compiled glyph: $< → $@"

# Cleanse the realm
clean:
    rm -rf build bin
    @echo "🧹 Realm cleansed"

.PHONY: all clean
