#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CTriangle.h"
#include"addtriangleaction.h"





addtriaction::addtriaction(ApplicationManager* pApp) :Action(pApp)
{
}
void addtriaction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Triangle: Click at first corner");
	//Read 1st vertex and store it
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("New Triangle: Click at second corner");
	//Read 2nd vertex and store it
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->PrintMessage("New Triangle: Click at third corner");
	//Read 3rd vertex and store it
	pIn->GetPointClicked(P3.x, P3.y);
	RectGfxInfo.isFilled = UI.isFilled; //  the current fill state
	if (UI.isFilled)
		RectGfxInfo.FillClr = UI.FillColor; //  the selected fill color
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();
}

void addtriaction::Execute()
{
	//read parameters first
	ReadActionParameters();
	//Create a triangle 
	CTriangle* T = new CTriangle(P1, P2, P3, RectGfxInfo);
	//Add the triangle to the array of figures
	pManager->AddFigure(T);

	
	pManager->UpdateInterface();
}

