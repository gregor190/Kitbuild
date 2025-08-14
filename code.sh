#!/bin/bash
# 🧞 code.sh – Summons a context-aware Makefile for Kitbuild

echo "📜 Overriding Makefile with dist-aware logic..."

cat > Makefile <<EOF
# 🧟 Kitbuild Makefile – Dist Ritual + Meta Naming

CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude
SRC = \$(wildcard src/**/*.c) \$(wildcard main/*.c)
OBJ = \$(patsubst %.c,build/%.o,\$(SRC))

# Default binary name
BIN_NAME = kitbuild

# Meta tag (e.g., gen1, v1.2.3)
META ?= default

# Output directory logic
ifeq (\$(shell test -d dist && echo yes),yes)
    BIN_DIR = dist
else
    BIN_DIR = bin
endif

BIN = \$(BIN_DIR)/\$(BIN_NAME)-\$(META)

# 🧙‍♂️ Ritual: Build all
all: \$(BIN)

# 🧱 Link objects into binary
\$(BIN): \$(OBJ)
    @mkdir -p \$(BIN_DIR)
    \$(CC) \$(OBJ) -o \$(BIN)
    @echo "🔮 Linked binary: \$(BIN)"

# ⚙️ Compile each source file into object
build/%.o: %.c
    @mkdir -p \$(dir \$@)
    \$(CC) \$(CFLAGS) -c \$< -o \$@
    @echo "⚙️ Compiled glyph: \$< → \$@"

# 🧹 Cleanse the realm
clean:
    rm -rf build bin dist
    @echo "🧼 Realm cleansed"

# 📜 Show rituals
info:
    @echo "🧾 Kitbuild Meta: \$(META)"
    @echo "📦 Output Path: \$(BIN)"

.PHONY: all clean info
EOF

echo "✅ Makefile forged with dist/meta logic."
echo "🧪 Try: make meta=gen1"
echo "📜 Or: make info"

