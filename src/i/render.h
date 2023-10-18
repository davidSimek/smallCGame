#ifndef render_h
#define render_h

#include "obstacles.h"

void render(char* buffer, int bufferSize, int x, int y, char* player, Obstacle* obstacles, int obstacleCount, Obstacle** focussedObstacle);
#endif
