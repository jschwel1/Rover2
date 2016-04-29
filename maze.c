/*
* File: Maze.c
* Written by: Jacob Schwell & Ryan Cuddy
* EECE 287
* 04/26/2016
* Description: This file contains the function implementations to help guide
* the rover through a maze. It utilizes a combination of QTR_driver and motor
* functions.
*/

#include "maze.h"
#include "qtr_driver.h"
#include "motor.h"

void navigateMaze(){
	unsigned char value;
	// Operates by right-hand search:
	//	1) Right turn available? take it
	// 	2) No right turn, try forward
	//	3) Can't go forward? what about left?
	//	4) Dead end, do a U-turn and try again...
	while (1){
		value = get_QTR_value();
		
		// follow a line
		if (value == 0x0F) driveForward(); 		// 0000 1111
		else if (value == 0x1F) curveLeft(); 	// 0001 1111 Was Left
		else if (value == 0x3F) rotateCCW(); 	// 0011 1111 Was CCW
		else if (value == 0x07) curveRight(); 	// 0000 0111 Was Right
		else if (value == 0x03) rotateCW(); 	// 0000 0011 Was CW

		// right turn
		else if (value == 0x00) rotateCW(); 	// 0000 0000 Was Right
		else if (value == 0x01) rotateCW(); 	// 0000 0001 Was CW

		// dead end/left turn
		else if (value == 0xFF) rotateCCW();		// 1111 1111 Was Left 
		else if (value == 0x7F) rotateCCW();		// 0111 1111 Was CCW
		
		// default:
		else driveBackward();
	}
	
}


