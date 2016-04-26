/*
* File: motor.c
* Written by: Jacob Schwell & Ryan Cuddy
* EECE 287
* 4/25/2016
* This file contains the implementations of all the functions used in motor.h.
*/

#include "motor.h"
#include "qtr_driver.h"
#include <math.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/io.h>



void coast(){
	setMotorR(COAST);
	setMotorL(COAST);
	_delay_ms(10);
}

void stop(){
	setMotorR(BRAKE);
	setMotorL(BRAKE);
	_delay_ms(10);
}

void driveForward(){
	setMotorR(FORWARD);
	setMotorL(FORWARD);
}

void driveBackward(){
	setMotorR(REVERSE);
	setMotorL(REVERSE);
}

void rotateCW(){
	setMotorR(REVERSE);
	setMotorL(FORWARD);
}

void rotateCCW(){
	setMotorR(FORWARD);
	setMotorL(REVERSE);
}

void curveRight(){
	setMotorR(COAST);
	setMotorL(FORWARD);
}

void curveLeft(){
	setMotorR(FORWARD);
	setMotorL(COAST);
}

void setUp(){
	// set motor & encoder port/pin to 
	DDRC = 0x0F;
	
	// initialize the QTR sensor as defined in qtr_driver.c
	init_QTR_driver();
	
}

/**** clean up setMotor functions**/
void setMotorR(unsigned char dir){
	MOTORS = (MOTORS&~(0x03<<MOTOR_R) | (dir << MOTOR_R));
}

void setMotorL(unsigned char dir){
	MOTORS = (MOTORS&~(0x03<<MOTOR_L) | (dir << MOTOR_L));
}

void U_turn(){
	left90();
}

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
		if (value == 0x0F) driveForward(); // 0000 1111
		else if (value == 0x1F) curveLeft(); // 0001 1111
		else if (value == 0x3F) rotateCCW(); // 0011 1111
		else if (value == 0x07) curveRight(); // 0000 0111
		else if (value == 0x03) rotateCW(); // 0000 0011

		// right turn
		else if (value == 0x00) right90();
		else if (value == 0x01) rotateCW();

		// Dead end/left turn
		else if (value == 0xFF) left90();
		else if (value == 0x7F) rotateCCW();
		
		// default:
		else stop();


		_delay_ms(10);
	}
	
}

void hardTurnRight(){
	setMotorL(BRAKE);
	setMotorR(FORWARD);
}

void hardTurnLeft(){
	setMotorR(BRAKE);
	setMotorL(FORWARD);
}
