#!/bin/bash

echo "Generating lexer and parser code..."
antlr4 -Dlanguage=Cpp CACT.g4


