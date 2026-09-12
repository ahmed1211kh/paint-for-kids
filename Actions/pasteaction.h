#pragma once
#include "Action.h"
#ifndef PASTE_ACTION
#define PASTE_ACTION
class Paste : public Action
{


private:
	Point location2;
public:
	Paste(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif

