#include "swtodraw.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"


swtodraw::swtodraw(ApplicationManager* pApp) : Action(pApp)
{
}

void swtodraw::ReadActionParameters()
{
}

void swtodraw::Execute()
{

    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    // Switch to the draw mode toolbar
    pOut->CreateDrawToolBar();
    pManager->UnselectAllFigures();
    // Display a message to the user
    pOut->PrintMessage("Switched to Draw Mode. Original graph restored.");
    pManager->UpdateInterface();
}

swtodraw::~swtodraw()
{
}