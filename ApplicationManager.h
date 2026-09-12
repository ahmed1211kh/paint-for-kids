#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	CFigure* Clipboard;  //Pointer to copied/cut figure
	int RectCount = 0, TriCount = 0, HexCount = 0, CirCount = 0, SqrCount = 0;

public:	
	ApplicationManager(); 
	~ApplicationManager();

	
	void RemoveFigureAtIndex(int index); // Removes a figure at a specific index
	void ClearFigures();
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure* GetSelectedFigure() const; // Returns the selected figure
	void UnselectAllFigures(); // Unselect all figures
	int GetFigCount() const; // Returns the number of figures
	CFigure* GetFigureAtIndex(int index) const; // Returns the figure
	void PrintSelectedFiguresInfo() const; // Print info of selected figures
	void SetClipboard(CFigure* fig); // Sets the clipboard to the given figure
	CFigure* GetClipboard() const;  // get the figure in the clipboard
	void ClearClipboard();          // Clear the clipboard and restore the figure's  colors
	              
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void RemoveFigure(CFigure* fig); // Remove a figure from the list
	void copyclipboard(CFigure* Fig); // for copy action
	CFigure* getcopyclipboard(); // for copy action
	void SaveAll(std::ofstream& outFile) const; // to save figures
	
};

#endif