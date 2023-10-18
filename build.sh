#!/bin/bash

if [[ $* == *-g* ]]; then
    gcc -g -o run src/main.c src/flow.c src/input.c src/movement.c src/obstacles.c src/render.c src/terminal.c
    echo "built with gdb flags"
else
    gcc -o run src/main.c src/flow.c src/input.c src/movement.c src/obstacles.c src/render.c src/terminal.c
    echo "built without gdb flags"
fi
