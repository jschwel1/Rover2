/*
* File: motor.c
* Written by: Jacob Schwell & Ryan Cuddy
* EECE 287
* 05/04/2016
* This file contains the implementations of all the functions used in motor.h.
*/

#include "motor.h"


void coast(){
	setMotorR(COAST);
	setMotorL(COAST);
}

void stop(){
	setMotorR(BRAKE);
	setMotorL(BRAKE);
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

void hardTurnRight(){
	setMotorL(BRAKE);
	setMotorR(FORWARD);
}

void hardTurnLeft(){
	setMotorR(BRAKE);
	setMotorL(FORWARD);
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
	MOTOR_PORT_DDR = MOTOR_MASK;
}


void setMotorR(unsigned char dir){
	MOTOR_PORT = (MOTOR_PORT&~(0x03<<MOTOR_R) | (dir << MOTOR_R));
}

void setMotorL(unsigned char dir){
	MOTOR_PORT = (MOTOR_PORT&~(0x03<<MOTOR_L) | (dir << MOTOR_L));
}


