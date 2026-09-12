#ifndef SWTOPLAY_H
#define SWTOPLAY_H

#include "Action.h"

class swtoplay : public Action {
public:
    swtoplay(ApplicationManager* pApp); // Constructor
    virtual void ReadActionParameters() override; // Reads parameters (if any)
    virtual void Execute() override; // Executes the action
};

#endif


