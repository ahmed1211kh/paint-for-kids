#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#include "Action.h"
#include "ClearAll.h"
ClearAll::ClearAll(ApplicationManager* pApp) : Action(pApp) {}

void ClearAll::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Cleared All");
}

void ClearAll::Execute()
{
	ReadActionParameters();
	pManager->ClearFigures(); // Clear all figures
	pManager->UpdateInterface();
}

ClearAll::~ClearAll()
{
}
