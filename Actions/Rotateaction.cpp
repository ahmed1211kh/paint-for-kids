#include "Rotateaction.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"

RotateAction::RotateAction(ApplicationManager* pApp) : Action(pApp) {}
void RotateAction::ReadActionParameters() {
    // Get the clicked point from the user
    Input* pIn = pManager->GetInput();
    Output* pOut = pManager->GetOutput();

    pOut->PrintMessage("Click on a figure to rotate.");
    pIn->GetPointClicked(clicked.x, clicked.y);

    // Get the figure at the clicked point
    selectedFigure = pManager->GetFigure(clicked.x, clicked.y);

    if (selectedFigure == nullptr) {
        pOut->PrintMessage("No figure selected");
    }
    else {
        pOut->PrintMessage("Figure selected");
    }
}
void RotateAction::Execute() {
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    int x, y;
    pIn->GetPointClicked(x, y); // Get the point clicked by the user

    CFigure* selectedFigure = pManager->GetFigure(x, y); // Pass the clicked point to GetFigure

    if (!selectedFigure) {
        pOut->PrintMessage("No figure selected");
        return;
    }

    // Clear the old figure from the drawing area
    pOut->ClearDrawArea();

    // Rotate the figure by 90 degrees
    selectedFigure->Rotate90();

    // Redraw all figures again , including the rotated one
    pManager->UpdateInterface();

    pOut->PrintMessage("Figure rotated by 90 degrees.");
    pManager->UpdateInterface();
}
RotateAction::~RotateAction() {
	
}