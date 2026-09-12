#include"togglefillaction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"
#include "..\DEFS.h"



ToggleFillAction::ToggleFillAction(ApplicationManager* pApp) : Action(pApp) {}

void ToggleFillAction::ReadActionParameters() {}

void ToggleFillAction::Execute()
{
    Output* pOut = pManager->GetOutput();

    // Toggle the fill state
    UI.isFilled = !UI.isFilled;

    if (UI.isFilled)
        pOut->PrintMessage("Fill mode enabled.");
    else
        pOut->PrintMessage("Fill mode disabled.");
    pManager->UpdateInterface();
}
