#include "i/input.h"

#include <stddef.h>

#include "i/obstacles.h"
#include "i/constants.h"
#include "i/movement.h"

void handleInput(int* x, int* y, int ch, char* player, Obstacle* obstacles, int obstacleCount, Obstacle** focussedObstacle) {
    int movingTo = UP;

    if (ch == 'a') {
        movingTo = LEFT;
        *player = '<';
    }
    else if (ch == 'd') {
        movingTo = RIGHT;
        *player = '>';
    }
    else if (ch == 'w') {
        movingTo = UP;
        *player = '^';
    }
    else if (ch == 's') {
        movingTo = DOWN;
        *player = '_';
    }

    Obstacle* obstacle = colidesWith(*x, *y, movingTo, obstacles, obstacleCount);
    if (obstacle != NULL) {
        // handle obstacle here
        *focussedObstacle = obstacle;
        return;
    }
    *focussedObstacle = NULL;
 
    if (movingTo == LEFT)
        moveLeft(x, y);
    else if (movingTo == RIGHT)
        moveRight(x, y);
    else if (movingTo == UP)
        moveUp(x, y);
    else if (movingTo == DOWN)
        moveDown(x, y);
}
