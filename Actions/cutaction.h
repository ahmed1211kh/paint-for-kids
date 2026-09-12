#pragma once
#include "Action.h"

class CutAction : public Action {
public:
    CutAction(ApplicationManager* pApp);
    virtual void Execute();
    virtual void ReadActionParameters() override {};
};
