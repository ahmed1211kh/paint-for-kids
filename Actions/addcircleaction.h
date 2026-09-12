#ifndef		ADD_CIRCLE_ACTION 
#define		ADD_CIRCLE_ACTION
#endif 
#include "Action.h"

class addcircaction : public Action
{
private:
	Point P1, P2; //Circle points
	GfxInfo RectGfxInfo;
public:
	addcircaction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};