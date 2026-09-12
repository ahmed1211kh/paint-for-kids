#ifndef TOGGLE_FILL_ACTION_H
#define TOGGLE_FILL_ACTION_H

#include "Action.h"

class ToggleFillAction : public Action
{
public:
    ToggleFillAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};
#endif
