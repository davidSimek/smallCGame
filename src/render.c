#include "i/render.h"

#include <stdbool.h>

#include "i/obstacles.h"
#include "i/constants.h"

void render(char* buffer, int bufferSize, int x, int y, char* player, Obstacle* obstacles, int obstacleCount, Obstacle** focussedObstacle) {
    int counter = 0;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            bool foundObstacle = false;

            // draw obstacles
            for (int k = 0; k < obstacleCount; k++) {
                Obstacle* currentObstacle = &obstacles[k];
                if (currentObstacle->x == j && currentObstacle->y == i) {
                    buffer[counter++] = currentObstacle->symbol;
                    buffer[counter++] = ' ';
                    foundObstacle = true;
                    break;
                }
            }

            // draw player
            if (foundObstacle) {
                continue;
            }
            foundObstacle = false;
            if (i == y && j == x) {
                buffer[counter++] = *player;
                buffer[counter++] = ' ';
            } else {
                buffer[counter++] = ' ';
                buffer[counter++] = ' ';
            }
        }
        buffer[counter++] = '\n';
    }
}
