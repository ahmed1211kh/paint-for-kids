#include "Swapaction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"


SWAP::SWAP(ApplicationManager* pApp) : Action(pApp), FigCount(0) {
    // Initialize the array of figure pointers
    Figures = new CFigure * [2]; // Assuming we only need to swap two figures
    for (int i = 0; i < 2; ++i) {
        Figures[i] = nullptr;
    }


}

void SWAP::ReadActionParameters() {
    // Get the output pointer
    Output* pOut = pManager->GetOutput();

    // Reset the selected figures array
    FigCount = 0;

    // Iterate through all figures to find selected ones
    for (int i = 0; i < pManager->GetFigCount(); ++i) {
        CFigure* fig = pManager->GetFigureAtIndex(i); 
        if (fig && fig->IsSelected()) {
            if (FigCount < 2) {
                Figures[FigCount++] = fig;
            }
            else {
                // if more than two figures
                pOut->PrintMessage("Error: More than two figures selected. Please select exactly two figures.");
                return;
            }
        }
    }

    if (FigCount < 2) {
        // Less than two figures selected
        pOut->PrintMessage("Error: Less than two figures selected. Please select exactly two figures.");
    }
}

void SWAP::Execute() {
    
    ReadActionParameters();

    // If the number of selected figures is not exactly two exit the program


    // make the swap
    Point tempPosition1 = Figures[0]->GetPosition1();
    Point tempPosition2 = Figures[0]->GetPosition2();
    Point tempPosition3 = Figures[0]->GetPosition3();

    Figures[0]->SetPosition(Figures[1]->GetPosition1(), Figures[1]->GetPosition2(), Figures[1]->GetPosition3());
    Figures[1]->SetPosition(tempPosition1, tempPosition2, tempPosition3);
    // Update the interface 
    pManager->UpdateInterface();

    // Display a message to the user
    pManager->GetOutput()->PrintMessage("Swap action completed successfully.");
}