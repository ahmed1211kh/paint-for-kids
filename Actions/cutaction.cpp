#include "cutaction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


CutAction::CutAction(ApplicationManager* pApp) : Action(pApp) {}

void CutAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
    CFigure* selectedFigure = pManager->GetSelectedFigure();
    if (selectedFigure == nullptr) {
        pOut->PrintMessage("No figure selected to cut!");
        return;
    }

    // Create a copy of the selected figure 
    CFigure* cutFigure = selectedFigure->shiftlocation();
    pManager->SetClipboard(cutFigure);
	// Set the draw color to gray
    
    selectedFigure->SetSelected(false);
	selectedFigure->ChngFillClr(selectedFigure->GetOriginalDrawColor());


  
  

    pOut->PrintMessage("Figure cut successfully!");
    pManager->UpdateInterface();
}
