#!/bin/bash
#make for mac

rm -rf build
mkdir build
gcc -std=c99 src/heap.c -o build/heap.o
gcc -std=c99 src/linkedlist.c -o build/linkedlist.o
gcc -std=c99 src/main.c -o build/main.o

