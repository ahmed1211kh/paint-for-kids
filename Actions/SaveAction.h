#pragma once
#include "Action.h"
class save :public Action
{
private:
    std::string fileName; // The name of the file to save to
public:
    save(ApplicationManager* pApp); // Constructor
    virtual void ReadActionParameters() override; // Reads the filename
    virtual void Execute() override; // Executes the save action
};

