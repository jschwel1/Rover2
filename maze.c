/*
* File: Maze.c
* Written by: Jacob Schwell & Ryan Cuddy
* EECE 287
* 04/26/2016
* Description: This file contains the function implementations to help guide
* the rover through a maze.
*/

#include "maze.h"

void left90(){
	unsigned char value = get_QTR_value();
	while (value == 0xFF || value == 0x7F || value == 0x3F){
		rotateCCW();
		value = get_QTR_value();
	}
	return;
}

void right90(){
	unsigned char value = get_QTR_value();
	while (value == 0x00 || value == 0x01 || value == 0x03){
		rotateCW();
		value = get_QTR_value();
	}
	return;
}

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
		else if (value == 0x1F) curveLeft(); 	// 0001 1111
		else if (value == 0x3F) rotateCCW(); 	// 0011 1111
		else if (value == 0x07) curveRight(); 	// 0000 0111
		else if (value == 0x03) rotateCW(); 	// 0000 0011

		// right turn
		else if (value == 0x00) right90(); 		// 0000 0000
		else if (value == 0x01) rotateCW(); 	// 0000 0001

		// dead end/left turn
		else if (value == 0xFF) left90();		// 1111 1111
		else if (value == 0x7F) rotateCCW();	// 0111 1111
		
		// default:
		else driveBackward();
	}
	
}


