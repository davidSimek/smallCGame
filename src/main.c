#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>

#include "i/obstacles.h"
#include "i/flow.h"
#include "i/constants.h"
#include "i/terminal.h"
#include "i/input.h"
#include "i/render.h"

char player = '>';

int main() {
    signal(SIGINT, shouldStop);
    // terminal config variables
    struct termios old, new;

    // obstacles
    int obstacleCount = 2;
    Obstacle* obstacles = (Obstacle*)malloc(sizeof(Obstacle) * obstacleCount);
    

    obstacles[0].name = "Mushroom";
    obstacles[0].message = "This is mushroom";
    obstacles[0].symbol = '#';
    obstacles[0].x = 4;
    obstacles[0].y = 3;

    obstacles[1].name = "Snake";
    obstacles[1].message = "This is a snake";
    obstacles[1].symbol = 'S';
    obstacles[1].x = 2;
    obstacles[1].y = 3;
    // graphics variables
    int bufferSize = HEIGHT * WIDTH + WIDTH + HEIGHT;
    char* buffer = (char*)malloc(bufferSize);
    int ch, x, y;
    ch = 0;
    x = 0;
    y = 0;

    Obstacle* focussedObstacle = NULL;
    
    setNonBlocking(&old, &new);

    while (shouldRun) {

        ch = getchar();
        if (ch != EOF) { // EOF == end of file
            
            handleInput(&x, &y, ch, &player, obstacles, obstacleCount, &focussedObstacle);
            render(buffer, bufferSize, x, y, &player, obstacles, obstacleCount, &focussedObstacle);
            clearConsole();
            printf("%s\n", buffer);
            if (focussedObstacle != NULL) {
                printf("- %s -\n    Message: %s", focussedObstacle->name, focussedObstacle->message);
            }
        }
    }

    free(buffer);
    free(obstacles);
    unsetNonBlockint(&old);
    return 0;
}












