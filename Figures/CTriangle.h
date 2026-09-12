#pragma once
#ifndef CTRI_H
#define CTRI_H
#include "CFigure.h"



class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool IsInside(int x, int y) const override;
	void Rotate90() override;
	virtual void Swap(CFigure* fig) override; // Override the Swap method
	virtual Point GetPosition1() const override;// Returns the first position of the triangle
	virtual Point GetPosition2() const override;
	virtual Point GetPosition3() const override;
	virtual void SetPosition(Point p1, Point p2 = Point{ -1, -1 }, Point p3 = Point{ -1, -1 }) override;
	virtual CFigure* shiftlocation() const override;
	virtual void Save(std::ofstream& outFile) const override;
	virtual void Load(std::ifstream& inputFile) override;
};
#endif 
