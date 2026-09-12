#include "CopyAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

COpy::COpy(ApplicationManager* pApp) : Action(pApp) {}

void COpy::ReadActionParameters() {
    //empty implentation to avoid  linker errors
}

void COpy::Execute() {
    // Get the selected figure
    CFigure* selectedFigure = pManager->GetSelectedFigure();

    if (selectedFigure) {
        // Copy the selected figure to the clipboard
        pManager->copyclipboard(selectedFigure);

       // message for the user
        pManager->GetOutput()->PrintMessage("Figure copied to clipboard.");
    }
    else {
        // if no figure is selected
        pManager->GetOutput()->PrintMessage("No figure selected to copy.");
    }
    pManager->UpdateInterface();
}