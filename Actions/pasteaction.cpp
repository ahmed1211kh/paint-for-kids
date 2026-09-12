#include "pasteaction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


Paste::Paste(ApplicationManager* pApp) : Action(pApp) {}

void Paste::ReadActionParameters() {
    // Get the new location from the user
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMessage("Click at the new location to paste the figure.");
    pIn->GetPointClicked(location2.x, location2.y);
    pOut->ClearStatusBar();
}

void Paste::Execute() {
    // Get the figure from the clipboard
    CFigure* clipboardFigure = pManager->GetClipboard();

    if (!clipboardFigure) {
        pManager->GetOutput()->PrintMessage("Clipboard is empty. No figure to paste.");
        return;
    }

    // Read the new location to paste
    ReadActionParameters();

    // Create a copy of the figure 
    CFigure* newFigure = clipboardFigure->shiftlocation();
    newFigure->SetPosition(location2);

    // Add the new figure to the application
    pManager->AddFigure(newFigure);

    // message to the user
    pManager->GetOutput()->PrintMessage("Figure pasted successfully.");
    // Create a copy of the clipboard figure and add it to the drawing area
    CFigure* PastedFigure = clipboardFigure->shiftlocation();
    pManager->AddFigure(PastedFigure);


    // Clear the clipboard
    pManager->ClearClipboard();
	pManager->UnselectAllFigures(); 

    // message to the user
    pManager->GetOutput()->PrintMessage("Figure pasted from clipboard.");
    pManager->UpdateInterface();
}