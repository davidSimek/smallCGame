#include "i/obstacles.h"

#include <stddef.h>

#include "i/constants.h"


Obstacle* colidesWith(int x, int y, int movingTo, Obstacle* obstacles, int obstacleCount) {
    if (movingTo == UP)
        y -= 1;
    if (movingTo == DOWN)
        y += 1;
    if (movingTo == LEFT)
        x -= 1;
    if (movingTo == RIGHT)
        x += 1;
    for (int i = 0; i < obstacleCount; i++) {
        Obstacle* currentObstacle = &obstacles[i];
        if (currentObstacle->x == x && currentObstacle->y == y) {
            return currentObstacle;
        }
    }
    return NULL;
}
