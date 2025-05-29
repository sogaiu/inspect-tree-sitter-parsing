#! /bin/sh

gcc \
  -g -O0 \
  -Itree-sitter/lib/include -Itree-sitter/lib/src \
  tree-sitter/lib/src/lib.c \
  -Itree-sitter-janet-simple/src \
  tree-sitter-janet-simple/src/parser.c \
  tree-sitter-janet-simple/src/scanner.c \
  -o sample \
  main.c
