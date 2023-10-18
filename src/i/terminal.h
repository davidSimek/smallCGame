#ifndef terminal_h
#define terminal_h

#include <termios.h>

void setNonBlocking(struct termios* oldT, struct termios* newT);
void unsetNonBlockint(struct termios* oldT);
void clearConsole();
#endif
