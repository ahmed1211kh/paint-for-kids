#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	SET_RED_COLOR,
	SET_BLUE_COLOR,
	SET_GREEN_COLOR,
	SET_BLACK_COLOR,
	SET_ORANGE_COLOR,
	EXIT,
	SET_YELLOW_COLOR,
	DRAW_RECT,
	DRAW_TRI,
	DRAW_SQR,
	DRAW_CIR,
	DRAW_HEX,
	SELECT_SHAPE,            //Select a shape
	TOGGLE_SHAPE,			//Switch between filled and unfilled shapes
	ROTATE_SHAPE, //Rotate the selected shape
	DELETE_SHAPE,          //Delete the selected shape
	ClEAR_SHAPE,           //Clear the drawing area
	SWAP_SHAPE,
	COPY_SHAPE,           //Copy the selected shape
	PASTE_SHAPE,          //Paste the copied shape
	CUT_SHAPE,//Cut the selected shape
	SAVE_SHAPE,
	LOAD_SHAPE,
	     //Save the selected shape


	
//Draw Rectangle//Exit
SWITCHTOPLAY,
			//Switch interface to Draw mode
			//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	PLAYING_AREA,
	STATUS	,
	SWITCHTODRAW,//A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr ;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif