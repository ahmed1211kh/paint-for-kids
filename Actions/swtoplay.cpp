#include "swtoplay.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"

swtoplay::swtoplay(ApplicationManager* pApp) : Action(pApp) {
    // Constructor initializes the action with the application manager
}

void swtoplay::ReadActionParameters() {
    // No parameters are required for this action
}

void swtoplay::Execute() {
    // Get a pointer to the Output interface
    Output* pOut = pManager->GetOutput();

    // Switch the interface to Play Mode
	pOut->cleardrawtoolbar();
    pOut->CreatePlayToolBar();

    // Display a message indicating the mode switch
    pOut->PrintMessage("Switched to Play Mode.");
}
