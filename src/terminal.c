#include "i/terminal.h"

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

void setNonBlocking(struct termios* oldT, struct termios* newT) {
    tcgetattr(STDIN_FILENO, oldT);
    *newT = *oldT;
    newT->c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, newT);
}
void unsetNonBlockint(struct termios* oldT) {
    tcsetattr(STDIN_FILENO, TCSANOW, oldT);
}
void clearConsole() {
    printf("\033[H\033[J");
}
