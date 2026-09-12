#pragma once
#include "Action.h"
#include <string>

class LoadAction : public Action {
private:
    std::string fileName; // The name of the file to load from
public:
    LoadAction(ApplicationManager* pApp); // Constructor
    virtual void ReadActionParameters() override; // Reads the filename
    virtual void Execute() override; // Executes the load action
};
