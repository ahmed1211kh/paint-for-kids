#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\addtriangleaction.h"
#include "Actions\addsquareaction.h"
#include "Actions\addcircleaction.h"
#include "Actions\addhexagonaction.h"
#include "Figures/CTriangle.h"
#include "Figures/CCircle.h"
#include "Figures/CRectangle.h"
#include "Figures/CSquare.h"
#include "Figures/CHexagon.h"
#include "Actions/selectshape.h"
#include "Actions/ToggleFillAction.h"
#include "Actions/Swapaction.h"
#include "Actions/copyaction.h"
#include "Actions/PasteAction.h"
#include "Actions/RotateAction.h" 
#include "Actions/Deletee.h"
#include "Actions/ClearAll.h"
#include "Actions/CutAction.h"
#include "Actions/SaveAction.h"
#include "Actions/LoadAction.h"
#include "Actions/swtoplay.h"
#include <iostream>
using namespace std;

using namespace std;
#include <iostream>

ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	

	Clipboard = nullptr;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	if (UI.InterfaceMode == MODE_DRAW) {
		switch (ActType)
		{
		case SET_RED_COLOR:
			pOut->SetCrntDrawColor(color(255, 0, 0)); //  red color
			pOut->PrintMessage("Red color selected.");
			return;
		case SET_BLUE_COLOR:
			pOut->SetCrntDrawColor(color(0, 0, 255)); //  blue color
			pOut->PrintMessage("Blue color selected.");
			return;
		case SET_GREEN_COLOR:
			pOut->SetCrntDrawColor(color(0, 255, 0)); //  green color
			pOut->PrintMessage("Green color selected.");
			return;
		case SET_BLACK_COLOR:
			pOut->SetCrntDrawColor(color(0, 0, 0)); //  black color
			pOut->PrintMessage("Black color selected.");
			return;
		case SET_ORANGE_COLOR:
			pOut->SetCrntDrawColor(color(255, 165, 0)); //  orange color
			pOut->PrintMessage("orange color selected.");
			return;
		case EXIT:
			pOut->PrintMessage("Exiting the program...");

			exit(0);
		case SET_YELLOW_COLOR:
			pOut->SetCrntDrawColor(color(255, 255, 0)); //  yellow color
			pOut->PrintMessage("yellow color selected.");
			return;

		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_TRI:
			pAct = new addtriaction(this);
			break;
		case DRAW_SQR:
			pAct = new addsqraction(this);
			break;
		case DRAW_CIR:
			pAct = new addcircaction(this);
			break;
		case DRAW_HEX:
			pAct = new addhexaction(this);
			break;
		case SELECT:
			pAct = new selectshape(this);
			break;
		case TOGGLE:
			pAct = new ToggleFillAction(this);
			break;
		case swaP:
			pAct = new SWAP(this);
			break;
		case COPY:
			pAct = new COpy(this);
			break;
		case PASTE:

			pAct = new Paste(this);
			break;
		case ROTATE:
			pAct = new RotateAction(this);
			break;
		case dELETE:
			pAct = new Deletee(this);
			break;
		case CLEARALL:
			pAct = new ClearAll(this);
			break;
		case CUT:
			pAct = new CutAction(this);
			break;
		case SAVE:
			pAct = new save(this);
			break;
		case LOAD:
			pAct = new LoadAction(this);
			break;
		case TO_PLAY:
			pAct = new swtoplay(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
		}
	}
	else if(UI.InterfaceMode==MODE_PLAY)
	{
		switch (ActType)
		{
	
	
		case STATUS: // A click on the status bar
			return;
		case TO_DRAW:
			pAct = new swtoplay(this);
			break;
		
			
		}
	}

	

	
	


            
													

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;
		pAct = NULL;
	}
	}

void ApplicationManager::RemoveFigure(CFigure* fig)
{
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] == fig) {
			delete FigList[i];


			// Delete the figure
			FigList[i] = nullptr; //null pointer
			// Shift remaining figures 
			for (int j = i; j < FigCount - 1; j++) {
				FigList[j] = FigList[j + 1];
			}
			FigList[FigCount - 1] = nullptr; // Set the last pointer to null
			FigCount--; // Decrease the figure count
			break;
		}
	}
}
void ApplicationManager::copyclipboard(CFigure* Fig)
{
	Clipboard = Fig; //  clipboard for   the figure for the copy action figure

}
CFigure* ApplicationManager::getcopyclipboard()
{
	return Clipboard;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////

CFigure* ApplicationManager::GetFigure(int x, int y) const {
	for (int i = FigCount - 1; i >= 0; i--) { // Iterate from topmost figure
		if (FigList[i] != NULL && FigList[i]->IsInside(x, y)) {
			return FigList[i];
		}
	}
	return NULL; // No figure found
}
CFigure* ApplicationManager::GetSelectedFigure() const
{
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected()) {
			return FigList[i]; // Return the selected figure
		}
	}
	return NULL;
}
void ApplicationManager::SetClipboard(CFigure* fig) {
	Clipboard = fig; // setter for the  to the given figure
	
	if (Clipboard) {
		Clipboard->ChngDrawClr(Clipboard->GetOriginalDrawColor()); //original drawing color of the 
		Clipboard->ChngFillClr(Clipboard->GetOriginalFillColor());// original filling color
	}
	// Change the color to gray
	if (Clipboard) {
		Clipboard->ChngDrawClr(GRAY);
		Clipboard->ChngFillClr(GRAY);
	}
}

CFigure* ApplicationManager::GetClipboard() const {
	return Clipboard; // Return the figure to  clipboard
}
void ApplicationManager::ClearClipboard() {
	if (Clipboard) {
		Clipboard->ChngDrawClr(Clipboard->GetOriginalDrawColor());
		Clipboard->ChngFillClr(Clipboard->GetOriginalFillColor());
		Clipboard = nullptr;
	}

}
void ApplicationManager::SaveAll(std::ofstream& outFile) const {
	for (int i = 0; i < FigCount; ++i) {
		if (FigList[i] != nullptr) {
			FigList[i]->Save(outFile); // Call Save for each figure
			outFile << std::endl; 


		}
	}
	outFile << FigCount << endl;


}



	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	
void ApplicationManager::UnselectAllFigures() {
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->SetSelected(false); // Unselect all figures
	}
}

void ApplicationManager::PrintSelectedFiguresInfo() const {
	int RectCount = 0, TriCount = 0, HexCount = 0, CirCount = 0, SqrCount = 0;

	// Count selected figures by the type of each
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected()) {
			if (dynamic_cast<CRectangle*>(FigList[i])) RectCount++;
			else if (dynamic_cast<CTriangle*>(FigList[i])) TriCount++;
			else if (dynamic_cast<cHexagon*>(FigList[i])) HexCount++;
			else if (dynamic_cast<cCircle*>(FigList[i])) CirCount++;
			else if (dynamic_cast<cSquare*>(FigList[i])) SqrCount++;
		}
	}

	// Print the count and type of selected figures
	Output* pOut = GetOutput();
	if (RectCount + TriCount + HexCount + CirCount + SqrCount == 0) {
		pOut->PrintMessage("No figures selected.");
	}
	else {
		std::string message = "Selected: ";
		if (RectCount > 0) message += std::to_string(RectCount) + " Rectangle(s), ";
		if (TriCount > 0) message += std::to_string(TriCount) + " Triangle(s), ";
		if (HexCount > 0) message += std::to_string(HexCount) + " Hexagon(s), ";
		if (CirCount > 0) message += std::to_string(CirCount) + " Circle(s), ";
		if (SqrCount > 0) message += std::to_string(SqrCount) + " Square(s), ";
		message.pop_back(); 
		message.pop_back();
		pOut->PrintMessage(message);
	}
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures for the user
void ApplicationManager::UpdateInterface() const {
	pOut->ClearDrawArea(); // Clear the drawing area
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] != nullptr) {
			FigList[i]->Draw(pOut); // draw  figure again
		}
	}
	
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
int ApplicationManager::GetFigCount() const {
	return FigCount;
}

CFigure* ApplicationManager::GetFigureAtIndex(int index) const {
	if (index >= 0 && index < FigCount) {
		return FigList[index];
	}
	return nullptr;
}
void ApplicationManager::RemoveFigureAtIndex(int index) {
	if (index >= 0 && index < FigCount) {
		for (int i = index; i < FigCount - 1; i++) {
			FigList[i] = FigList[i + 1]; // Shift figures to fill the gap
		}
		FigList[--FigCount] = nullptr; // Decrease the figure count and nullify the last slot
	}
}
void ApplicationManager::ClearFigures()
{  // Delete all the figures 
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];  // Delete each figure
		FigList[i] = nullptr; // Set the pointer to nullptr
	}
	FigCount = 0; // Reset the count to 0
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager() {
	// Delete all figures
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
		FigList[i] = nullptr;
	}

	// Delete input and output objects
	delete pIn;
	pIn = nullptr;

	delete pOut;
	pOut = nullptr;
}
