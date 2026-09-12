#pragma once
#include "Action.h"
class swtodraw :
	public Action
{
public:
	swtodraw(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~swtodraw();
};
