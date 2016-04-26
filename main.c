/*
* File: main.c
* Written by: Jacob Schwell & Ryan Cuddy
* EECE 287
* 4/17/2016
* Description: This file utilizes the functions declared and defined in motor.h
* and motor.c, respectively. 
*/
#include "motor.h"

//#include "qtr_driver.h"
//#include <util/delay.h>

int main(){
	setUp();

	unsigned char value;
	navigateMaze();
/*
	while (1){
		value = get_QTR_value();

		// drive forward		
		if (value == 0x0F) driveForward();
		else if (value == 0xF0) driveBackward();
		else if (value == 0x1F) curveLeft();
		else if (value == 0x07) curveRight();
		// Left turn
		else if (value == 0x00) right90();
		// U-turn
		else if (value == 0xFF) U_turn();
		else stop();

		// give the rover a chance to move
//		_delay_ms(10);

	}
	
*/
	return 0;
}
