/*
* File: Maze.h
* Written by: Jacob Schwell & Ryan Cuddy
* EECE 287
* 04/26/2016
* Description: This file declares functions to be used to guide the Rover 5 
* Through a line-maze.
*/

#ifndef MAZE_H
#define MAZE_H

#define BLACK 0xFF
#define WHITE 0x00

#define ON_LINE 			((WHITE & 0xF0) | (BLACK & 0x0F)) // WWWW BBBB
#define RIGHT_DRIFT 		((WHITE & 0xE0) | (BLACK & 0x1F)) // WWWB BBBB
#define LEFT_DRIFT 			((WHITE & 0xF8) | (BLACK & 0x03)) // WWWW WBBB
#define OFF_TO_THE_RIGHT 	((WHITE & 0xC0) | (BLACK & 0x3F)) // WWBB BBBB
#define OFF_TO_THE_LEFT 	((WHITE & 0xFC) | (BLACK & 0x03)) // WWWW WWBB
#define ALMOST_ALL_BLACK 	((WHITE & 0x80) | (BLACK & 0x7F)) // WBBB BBBB
#define ALMOST_ALL_WHITE 	((WHITE & 0xF7) | (BLACK & 0x01)) // WWWW WWWB
#define ALL_WHITE 			(WHITE)							  // WWWW WWWW
#define ALL_BLACK 			(BLACK)							  // BBBB BBBB

// navigateMaze() utilizes the functions in this file, motor.h, 
// and qtr_driver.h to drive through the maze using a right-hand search.
void navigateMaze();

#endif
