#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"


class CRectangle : public CFigure
{
private:
Point Corner1;	
Point Corner2;
public:
CRectangle(Point , Point, GfxInfo FigureGfxInfo );
virtual void Draw(Output* pOut) const ;
virtual bool IsInside(int x, int y) const ;
 // Ensure base class has this method
void Rotate90() override;
virtual void Swap(CFigure* fig) override; // Override the Swap method
virtual Point GetPosition1() const override;// Returns the first position of the rectangle
virtual Point GetPosition2() const override;
// Returns the second position of the rectangle
virtual void SetPosition(Point p1, Point p2 = Point{ -1, -1 }, Point p3 = Point{ -1, -1 }) override;
virtual CFigure* shiftlocation() const override;
virtual void Save(std::ofstream& outFile) const override;
virtual void Load(std::ifstream& inputFile) override;
};

    #endif
