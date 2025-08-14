#!/bin/bash

# Define expected folders
folders=(
  "Kitbuild/main"
  "Kitbuild/src/parser"
  "Kitbuild/src/builder"
  "Kitbuild/src/logger"
  "Kitbuild/src/config"
  "Kitbuild/include"
)

# Define expected files
files=(
  "Kitbuild/main/main.c"
  "Kitbuild/src/parser/loader.c"
  "Kitbuild/src/parser/scanner.c"
  "Kitbuild/src/parser/resolver.c"
  "Kitbuild/src/parser/merge.c"
  "Kitbuild/src/builder/executor.c"
  "Kitbuild/src/builder/compiler.c"
  "Kitbuild/src/logger/narrator.c"
  "Kitbuild/src/config/config.c"
  "Kitbuild/include/parser.h"
  "Kitbuild/include/builder.h"
  "Kitbuild/include/logger.h"
  "Kitbuild/include/config.h"
  "Kitbuild/include/kitbuild.h"
)

echo "🔍 Checking and forging Kitbuild structure..."

# Check and create folders
for dir in "${folders[@]}"; do
  if [ -d "$dir" ]; then
    echo "[FOLDER-OK] $dir"
  else
    echo "[FOLDER-MISSING] $dir → creating..."
    mkdir -p "$dir"
  fi
done

# Check and create files
for f in "${files[@]}"; do
  if [ -f "$f" ]; then
    echo "[FILE-OK] $f"
  else
    echo "[FILE-MISSING] $f → touching..."
    touch "$f"
  fi
done


