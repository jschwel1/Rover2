/*
* File: main.c
* Written by: Jacob Schwell & Ryan Cuddy
* EECE 287
* 4/17/2016
* Description: This file utilizes the functions declared and defined in motor.h
* and motor.c, respectively, in order to guide the Rover 5 through a maze.
*/
#include "motor.h"

//#include "qtr_driver.h"
//#include <util/delay.h>

int main(){
	setUp();

	
	navigateMaze();

	return 0;
}
