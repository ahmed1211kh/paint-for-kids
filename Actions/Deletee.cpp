#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#include "Deletee.h"
#include "Action.h"

Deletee::Deletee(ApplicationManager* pApp) : Action(pApp) {}

void Deletee::ReadActionParameters() {
    // No parameters to read for delete action
    Output* pOut = pManager->GetOutput();
    pOut->PrintMessage("Deleting selected figures...");
}

void Deletee::Execute() {
    // 
    ReadActionParameters();

    Output* pOut = pManager->GetOutput();

    // Loop  all figures and delete the selected ones
    bool foundSelected = false; // if any figure selected
    for (int i = 0; i < pManager->GetFigCount(); i++) {
        CFigure* figure = pManager->GetFigureAtIndex(i);
        if (figure != nullptr && figure->IsSelected()) {
            delete figure; // Delete the figure
            pManager->RemoveFigureAtIndex(i); // Remove it from the array of figures
            i--; 
            foundSelected = true; //  figure was deleted
        }
    }

    // Update the interface 
    pManager->UpdateInterface();

    // Print messages for the user to be informed
    if (foundSelected) {
        pOut->PrintMessage("Selected figures deleted.");
    }
    else {
        pOut->PrintMessage("No figures were selected to delete.");
    }
    pManager->UpdateInterface();
}

Deletee::~Deletee() {
}