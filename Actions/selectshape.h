
#pragma once
#include"Action.h"

class selectshape :public Action {
	Point clicked;
public:
	selectshape(ApplicationManager* pApp);
	//constructor
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
};
