/*
 * pong.c
 *
 *	Author: Matt Bergstedt
 *  Date: Oct 13, 2014
 *  Description: Provides instantiation for the pong header file.
 */

#include "pong.h"

// initializes the ball based on the parameters
ball drawBall(int xPos, int yPos, int xVel, int yVel, unsigned char rad){
	ball newBall;
	vector2d location;
	vector2d velocity;

	location.xVal = xPos;
	location.yVal = yPos;
	velocity.xVal = xVel;
	velocity.yVal = yVel;

	newBall.location = location;
	newBall.velocity = velocity;
	newBall.radius = rad;

	return newBall;
}

// moves the input ball by the velocities
ball moveBall(ball ballBeingMoved){
	// store the locations in new vectors to be used in the function
	vector2d location = ballBeingMoved.location;
	vector2d velocity = ballBeingMoved.velocity;

	// check if the ball will go out of bounds in x axis
	if(detectBounce(location.xVal,ballBeingMoved.radius,SCREEN_WIDTH,0))
	{
		velocity.xVal = -velocity.xVal;
	}
	// check if the ball will go out of bounds in y axis
	if(detectBounce(location.yVal,ballBeingMoved.radius,SCREEN_HEIGHT,0))
	{
		velocity.yVal = -velocity.yVal;
	}
	// update the location
	location.xVal += velocity.xVal;
	location.yVal += velocity.yVal;
	// put the location and velocity back into the ball structure to be used for the return
	ballBeingMoved.location = location;
	ballBeingMoved.velocity = velocity;

	return ballBeingMoved;
}

// use this function to detect if the ball has hit a wall
// use a ball that has no elasticity and bounces as soon as it touches the wall
char detectBounce(int pointToCheck, unsigned char radius, int upperLimit, int lowerLimit){
	// check if it is at or above the upper limit
	if(pointToCheck+radius/2 >= upperLimit){
		return TRUE;
	}
	// check if it is at or below the lower limit
	else if(pointToCheck-radius/2 <= lowerLimit){
		return TRUE;
	}
	else{
		return FALSE;
	}
}
