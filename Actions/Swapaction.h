#pragma once
#pragma once  
#ifndef SWAP_ACTION_H  
#define SWAP_ACTION_H  
#include "Action.h"  
#include "..\Figures\CFigure.h"  

#include "..\ApplicationManager.h"

class SWAP : public Action {
private:
    CFigure** Figures; // Array of pointers to figures  
    int FigCount;      // Number of figures  

public:
    SWAP(ApplicationManager* pApp);

    virtual void Execute() override;
    virtual void ReadActionParameters() override; // Declaration only, no body here
};

#endif