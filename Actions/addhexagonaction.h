#pragma once
#ifndef ADD_HEXAGON_ACTION_H
#define ADD_HEXAGON_ACTION_H
#include "Action.h"
class addhexaction : public Action
{
private:
	Point P1, P2;//hexagon two points
	GfxInfo RectGfxInfo;
public:
	addhexaction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif
