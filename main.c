#include <msp430g2553.h>
#include "pong.h"

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col, unsigned char color);

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

	unsigned char	x, y, button_press, color, radius, i;
	vector2d	location;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;


	init();
	initNokia();
	clearDisplay();
	x=4;		y=4;
	color=BLACK;
	radius=8;
	drawBlock(y,x,color);
	ball myBall=drawBall(8*x,8*y,X_VEL,Y_VEL,radius);
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
				clearDisplay();
				myBall = moveBall(myBall);
				location = myBall.location;
				drawBlock(location.yVal/8,location.xVal/8,color);
				for(i=0;i<255;i++);
//			}
		}
}
