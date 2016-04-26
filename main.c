/*
* File: main.c
* Written by: Jacob Schwell & Ryan Cuddy
* EECE 287
* 4/26/2016
* Description: This holds the main function to set up the QTR and motors in 
* before running the function to navigate the Rover 5 through the maze
*/
#include "motor.h"
#include "maze.h"

int main(){
	setUp();
	init_QTR_driver();

	navigateMaze();

	return 0;
}
