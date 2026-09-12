#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
class RotateAction : public Action {
private:
	Point clicked; // The point where the user clicked
	 CFigure* selectedFigure; // Pointer to the selected figure       
public:
    RotateAction(ApplicationManager* pApp);
    virtual void ReadActionParameters() override;
    virtual void Execute();
    virtual ~RotateAction();
};