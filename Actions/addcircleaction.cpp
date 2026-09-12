#include "addcircleaction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCircle.h"
addcircaction::addcircaction(ApplicationManager* pApp) :Action(pApp)
{
}
void addcircaction::ReadActionParameters()
{
	//get a pointer to the Inputclass  and Outputclass Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Circle: Click at center");
	//Read the center and store it
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("New Circle: Click at second corner");
	//Read a second point on the curve  and store it
	pIn->GetPointClicked(P2.x, P2.y);
	
//get drawing, filling colors and pen width from the interface
	RectGfxInfo.isFilled = UI.isFilled; //  the current fill state
	if (UI.isFilled)
		RectGfxInfo.FillClr = UI.FillColor; //  the selected fill color
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	
	pOut->ClearStatusBar();
}
void addcircaction::Execute()
{
	//read parameters first
	ReadActionParameters();
	//Create a circle 
	cCircle* C = new cCircle(P1, P2, RectGfxInfo);
	//Add the circle to the array of figures
	pManager->AddFigure(C);
	pManager->UpdateInterface();
}
