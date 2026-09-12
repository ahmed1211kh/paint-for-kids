#include "Action.h"#pragma once
class Rotate : public Action {
public:
    Rotate(ApplicationManager* pApp);
    virtual void Execute();
    virtual ~Rotate();
};