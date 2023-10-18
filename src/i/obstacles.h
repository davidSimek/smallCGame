#ifndef obstacles_h
#define obstacles_h
typedef struct {
    char* name;
    char* message;
    char symbol;
    int x;
    int y;
} Obstacle;

Obstacle* colidesWith(int x, int y, int movingTo, Obstacle* obstacles, int obstacleCount); // non blocking reading

#endif
