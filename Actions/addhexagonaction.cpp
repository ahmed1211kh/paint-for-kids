#include"addhexagonaction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CHexagon.h"
addhexaction::addhexaction(ApplicationManager* pApp) :Action(pApp)
{
}
void addhexaction::ReadActionParameters()
{
	//get a pointer to the Inputclass  and Outputclass Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Hexagon: Click at the center");
	//Read the center and store it
	pIn->GetPointClicked(P1.x, P1.y);
	
	
	RectGfxInfo.isFilled = UI.isFilled; //  the current fill state
	if (UI.isFilled)
		RectGfxInfo.FillClr = UI.FillColor; //  the selected fill color
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();
}
void addhexaction::Execute()
{
	//read parameters first
	ReadActionParameters();
	//Create a hexagon 
	cHexagon* H = new cHexagon(P1, RectGfxInfo);
	//Add the hexagon to the array of figures
	pManager->AddFigure(H);
	pManager->UpdateInterface();
}