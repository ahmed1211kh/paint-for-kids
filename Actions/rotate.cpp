#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
# include "rotate.h"
#include "../Figures/CFigure.h"
Rotate::Rotate(ApplicationManager* pApp) : Action(pApp) {}

void Rotate::Execute() {
    Output* pOut = pManager->GetOutput();
    CFigure* selectedFigure = pManager->GetFigure();

    if (!selectedFigure) {
        pOut->PrintMessage("No figure selected. Please select a single figure to rotate.");
        return;
    }

    if (selectedFigure->IsSelected() || selectedFigure->IsSelected()) {
        pOut->PrintMessage("Rotation has no effect on squares or circles.");
        return;
    }

    selectedFigure->rotate();
    pOut->PrintMessage("Figure rotated by 90 degrees.");
}


Rotate::~Rotate() {}