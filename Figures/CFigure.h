#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>

//Base class for all figures
 
    class CFigure  
    {  
    protected:  
       int ID; //Each figure has an ID  
       bool Selected; //true if the figure is selected.  
       GfxInfo FigGfxInfo; //Figure graphics info  
    private:
        color OriginalDrawColor= FigGfxInfo.DrawClr;
        color OriginalFillColor;

    public:  
        CFigure(GfxInfo FigureGfxInfo);

       void SetSelected(bool s); //select/unselect the figure  
       bool IsSelected() const; //check if fig is selected 
       void SetID(int id); // Set the ID of the figure
       int GetID() const; // Get the ID of the figure

       virtual void Draw(Output* pOut) const = 0; //Draw the figure  
       virtual bool IsInside(int x, int y) const = 0; //Check if a point is inside the figure 
       void ChngDrawClr(color Dclr); //changes the figure's drawing color  
       void ChngFillClr(color Fclr); //changes the figure's filling color  
	   virtual void Rotate90() = 0; //Rotate the figure by 90 degrees
       virtual void Swap(CFigure* fig) = 0; // Swap the position of two figures
       virtual Point GetPosition1() const = 0; // get the first position 
       virtual Point GetPosition2() const { return Point{ -1, -1 }; } // get second position
       virtual Point GetPosition3() const { return Point{ -1, -1 }; } // get third position
       virtual void SetPosition(Point p1, Point p2 = Point{ -1, -1 }, Point p3 = Point{ -1, -1 }) = 0; // Set the position of the figure
       virtual CFigure* shiftlocation() const = 0; //  to tke the figure and store it for the copy and paste
       color GetOriginalDrawColor() const;
       color GetOriginalFillColor() const;
	   virtual void Save(std::ofstream& outFile) const = 0; // Save the figure to a file

	   virtual void Load(std::ifstream& inputFile) = 0; // Load the figure from a file
    };  

    #endif
	
	/// Add more parameters if needed.


