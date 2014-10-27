ECE382_Lab4
===========
##C - "Etch-a-Sketch and Pong"
###Purpose
Use C to create an etch-a-sketch type program that utilizes some subroutines from lab 3.
###Preliminary Design
The pre-lab can be found in the repository.
###Hardware Design
The hardware for this lab is the LCD display on top of the MSP chip.
###Debugging
I ran the debugger to allow the program to be put on the chip.
###Testing Methodology/Results
To complete the required functionality, I added an input to drawBlock for the color and set it to listen for the aux button and flip the color.  In the nokia.asm file, I added an input through r14, and I checked that to set the value of the pixels that were being drawn.  To get it to perform like etch-a-sketch, I commented out the clearDisplay command in the final while loop, so that the display would keep the previous images.  To do inversion, I added an input of the color of the block to clearDisplay, and in the nokia.asm file I checked that input to set the value of the pixels covering the screen as opposite the block.  For B functionality, I included my pong files from assignment 6, and created a ball with the same values as the block to keep track of the movement.  I created a vector2d variable to keep the location and used that when redrawing the block.  To get it to draw in a visible manner on the display, I put a nested for loop to slow the program down, with the drawBlock at the innermost part of the loop.  For A functionality, I copied the drawBlock function in nokia.asm, adjusted the names for paddle, and removed the loop that drew multiple columns.  In the C file, I added the drawPaddle function and included it at the same location as the drawBlock was being called.  I then added checks for the buttons at the innermost part of the loops so that any inputs on the buttons would imediately take effect.  I also included a check for the row and column of both the paddle and the block to see if the block went past the paddle, and drew a blank screen if it did.
###Observations/Conclusions
Once I figured out how to make the needed adjustments to the given code, the functionalities were fairly simple to get.  Initially when I drew my bouncing block, I did not include a loop to delay the program, so it did not look like it was working.  Also, when I was doing my checking for a collision between the block and the paddle, the way I had the locations set up, I needed to divide the location of the block by 8.  Without this adjustment, my block would always miss and end after the first time it got to the wall.
###Documentation
None
