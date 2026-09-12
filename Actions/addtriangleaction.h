#pragma once
#ifndef ADD_TRI_ACTION
#define ADD_TRI_ACTION
#include "Action.h"

class addtriaction : public Action
{
private:
	Point P1, P2, P3; //Triangle Corners
	GfxInfo RectGfxInfo;
public:
	addtriaction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};




#endif // !ADD_TRI_ACTION
