#pragma once
#ifndef ADD_SQR_ACTION
#define ADD_SQR_ACTION
#include "Action.h"

class addsqraction : public Action
{
	Point p1;
	GfxInfo RectGfxInfo;
	int sidelength;
public:
	addsqraction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();





	//virtual ~addsqraction();
	//virtual void Undo();
	//virtual void Redo();
};









#endif
