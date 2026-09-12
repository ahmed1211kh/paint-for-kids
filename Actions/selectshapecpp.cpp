#include"selectshape.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
selectshape::selectshape(ApplicationManager* pApp) : Action(pApp) {}

void selectshape::ReadActionParameters() {
    // Get Input and Output interface  pointers 
    Input* pIn = pManager->GetInput();
    Output* pOut = pManager->GetOutput();

    // get point from the user 
    pOut->PrintMessage("Select a figure: Click on a figure or empty area.");
    pIn->GetPointClicked(clicked.x, clicked.y);

    // Clear the status bar
    pOut->ClearStatusBar();
}

void selectshape::Execute() {
    // Read the  point
    ReadActionParameters();

    // Get the figure at the  point
    CFigure* SelectedFigure = pManager->GetFigure(clicked.x, clicked.y);

    // If a figure is clicked
    if (SelectedFigure) {
        // Toggle selection
        if (SelectedFigure->IsSelected()) {
            SelectedFigure->SetSelected(false); // Unselect if already selected
        }
        else {
            SelectedFigure->SetSelected(true);
              // Select if not already selected
        }
    }
    else {
        // If no figure is clicked, unselect all figures
        pManager->UnselectAllFigures();
    }

    // Update the interface 
    pManager->UpdateInterface();

    // Print informationof the figures
    pManager->PrintSelectedFiguresInfo();
}