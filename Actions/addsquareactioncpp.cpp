#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CSquare.h"
#include "addsquareaction.h"

addsqraction::addsqraction(ApplicationManager* pApp) :Action(pApp)
{
}
void addsqraction::ReadActionParameters()
{
	//Get a Pointer to the Input and Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Square: Click at a point");
	//Read the center and store it
	pIn->GetPointClicked(p1.x, p1.y);
	RectGfxInfo.isFilled = UI.isFilled; //  the current fill state
	if (UI.isFilled)
		RectGfxInfo.FillClr = UI.FillColor; //  the selected fill color
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();
}
void addsqraction::Execute()
{
	//read parameters first
	ReadActionParameters();
	//Create a square 
	cSquare* S = new cSquare(p1,sidelength, RectGfxInfo);
	//Add the square to the array of figures
	pManager->AddFigure(S);
	pManager->UpdateInterface();

}

