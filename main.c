#include <msp430g2553.h>
#include "pong.h"

extern void init();
extern void initNokia();
extern void clearDisplay(unsigned char color);
extern void drawBlock(unsigned char row, unsigned char col, unsigned char color);
extern void drawPaddle(unsigned char row, unsigned char col, unsigned char color);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)
#define		BLACK			0
#define		WHITE			1
#define		X_VEL			8
#define		Y_VEL			8

void main() {

	unsigned char	xBall, yBall, button_press, color, radius, xPaddle, yPaddle;
	int	i, j;
	vector2d	location;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;


	init();
	initNokia();
	clearDisplay(BLACK);
	xBall=4;		yBall=4;
	xPaddle=0;		yPaddle=0;
	color=BLACK;
	radius=8;
	drawBlock(yBall,xBall,color);
	drawPaddle(yPaddle,xPaddle,color);
	ball myBall=drawBall(8*xBall,8*yBall,X_VEL,Y_VEL,radius);
	location = myBall.location;

	while(1) {

/*			if (UP_BUTTON == 0) {
				while(UP_BUTTON == 0);
				if (y>=1) y=y-1;
				button_press = TRUE;
			} else if (DOWN_BUTTON == 0) {
				while(DOWN_BUTTON == 0);
				if (y<=6) y=y+1;
				button_press = TRUE;
			} else if (LEFT_BUTTON == 0) {
				while(LEFT_BUTTON == 0);
				if (x>=1) x=x-1;
				button_press = TRUE;
			} else if (RIGHT_BUTTON == 0) {
				while(RIGHT_BUTTON == 0);
				if (x<=10) x=x+1;
				button_press = TRUE;
			} else if (AUX_BUTTON == 0) {
				while(AUX_BUTTON == 0);
				if(color == BLACK) color=WHITE;
				else if(color == WHITE) color=BLACK;
			}*/

//			if (button_press) {
//				button_press = FALSE;
				clearDisplay(color);
				myBall = moveBall(myBall);
				location = myBall.location;
				for(i=0;i<200;i++){
					for(j=0;j<30;j++){
						drawBlock(location.yVal/8,location.xVal/8,color);
						drawPaddle(yPaddle,xPaddle,color);
						if (UP_BUTTON == 0) {
							while(UP_BUTTON == 0);
							if (yPaddle>=1) yPaddle=yPaddle-1;
						} else if (DOWN_BUTTON == 0) {
							while(DOWN_BUTTON == 0);
							if (yPaddle<=6) yPaddle=yPaddle+1;
						} else if (AUX_BUTTON == 0) {
							while(AUX_BUTTON == 0);
							if(color == BLACK) color=WHITE;
							else if(color == WHITE) color=BLACK;
						}
						//check for collisions
						if(location.yVal==yPaddle)
						{
							if(location.xVal!=xPaddle){
								clearDisplay(BLACK);
								while(1);
							}
						}
					}
				}
//			}
		}
}
