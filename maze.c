/*
* File: Maze.c
* Written by: Jacob Schwell & Ryan Cuddy
* EECE 287
* 05/04/2016
* Description: This file contains the function implementations to help guide
* the rover through a maze. It utilizes a combination of QTR_driver and motor
* functions.
*/

#include "maze.h"
#include "qtr_driver.h"
#include "motor.h"

void navigateMaze(){
	unsigned char QTR_value;
	// Operates by right-hand search:
	//	1) Right turn available? take it
	// 	2) No right turn, try forward
	//	3) Can't go forward? what about left?
	//	4) Dead end, do a U-turn and try again...
	while (1){
		QTR_value = get_QTR_value();
		
		// follow a line
		if (QTR_value == ON_LINE) driveForward(); 
		else if (QTR_value == RIGHT_DRIFT) curveLeft();
		else if (QTR_value == OFF_TO_THE_RIGHT) rotateCCW();
		else if (QTR_value == LEFT_DRIFT) curveRight(); 
		else if (QTR_value == OFF_TO_THE_LEFT) rotateCW();

		// right turn
		else if (QTR_value == ALL_WHITE) rotateCW(); 
		else if (QTR_value == ALMOST_ALL_WHITE) rotateCW();

		// dead end/left turn
		else if (QTR_value == ALL_BLACK) rotateCCW();
		else if (QTR_value == ALMOST_ALL_BLACK) rotateCCW();
		
		// default:
		else driveBackward();
	}
	
}


