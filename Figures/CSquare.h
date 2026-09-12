#pragma once
#ifndef CSQR_H
#define CSQR_H
#include "CFigure.h"

class cSquare : public CFigure
{
private:
   
	Point center;
	int sideLength; // Length of the sides of the square
public:
	cSquare(Point , int sidelength,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool IsInside(int x, int y) const override; // Check if inside square
	void Rotate90() override {};
	virtual void Swap(CFigure* fig) override;
	virtual Point GetPosition1() const override;
	virtual Point GetPosition2() const override;
	virtual void SetPosition(Point p1, Point p2 = Point{ -1, -1 }, Point p3 = Point{ -1, -1 }) override;
	virtual CFigure* shiftlocation() const override;
	virtual void Save(std::ofstream& outFile) const override;
	virtual void Load(std::ifstream& inputFile) override;
};






#endif
