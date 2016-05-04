/*
* File: main.c
* Written by: Jacob Schwell & Ryan Cuddy
* EECE 287
* 5/04/2016
* Description: This file initialized the QTR sesnor and sets up the I/O pins 
* for the AVR processor.
*/


#include "motor.h"
#include "maze.h"

int main(){
	setUp();
	init_QTR_driver();

	navigateMaze();

	return 0;
}
