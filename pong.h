/*
 * pong.h
 *
 *  Author: Matt Bergstedt
 *  Date: Oct 13, 2014
 *  Description: Serves as the header file for the creation of a pong ball in pong
 */

#ifndef PONG_H_
#define PONG_H_

// define constants for the screen size
#define SCREEN_HEIGHT 56
#define SCREEN_WIDTH 88
// define constants for true and false
#define TRUE 1
#define FALSE 0

typedef struct{
	int xVal;
	int yVal;
} vector2d;

typedef struct{
	vector2d location;
	vector2d velocity;
	unsigned char radius;
} ball;

ball drawBall(int xPos, int yPos, int xVel, int yVel, unsigned char radius);

ball moveBall(ball ballBeingMoved);

char detectBounce(int pointToCheck, unsigned char radius, int upperLimit, int lowerLimit);

#endif /* PONG_H_ */
