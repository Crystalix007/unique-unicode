#! /bin/sh -e
mkdir -p "build"
g++ -Wall -Werror -pedantic --std=c++17 -c src/unique.cpp -o build/unique.o
g++ build/unique.o -o unique
