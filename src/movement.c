#include "i/movement.h"

#include "i/constants.h"

void moveLeft(int* x, int* y) {
    int ftrPos = *x - 1;
    if (ftrPos < 0) {
        *x = 0;
        return;
    }
    *x -= 1;
}
void moveRight(int* x, int* y) {
    int ftrPos = *x + 1;
    if (ftrPos >= WIDTH) {
        *x = WIDTH - 1;
        return;
    }
    *x += 1;
}
void moveUp(int* x, int* y) {
    int ftrPos = *y - 1;
    if (ftrPos < 0) {
        *y = 0;
        return;
    }
    *y -= 1;
}
void moveDown(int* x, int* y) {
    int ftrPos = *y + 1;
    if (ftrPos >= HEIGHT) {
        *y = HEIGHT - 1;
        return;
    }
    *y += 1;
}
