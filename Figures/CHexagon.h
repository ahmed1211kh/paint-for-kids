#pragma once
#ifndef CHEXAGON_H
#define CHEXAGON_H
#include "CFigure.h"
class cHexagon : public CFigure
{
private:
	Point point1;
	Point Vertices[6];
public:
	cHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool IsInside(int x, int y) const override;
	void Rotate90() override;
	virtual void Swap(CFigure* fig) override;
	// Override the Swap method
	virtual Point GetPosition1() const override;
	// Returns the first position of the hexagon
	virtual Point GetPosition2() const override;
	// Returns the second position of the hexagon
	virtual void SetPosition(Point p1, Point p2 = Point{ -1, -1 }, Point p3 = Point{ -1, -1 }) override;
	virtual CFigure* shiftlocation() const override;
	virtual void Save(std::ofstream& outFile) const override;
	virtual void Load(std::ifstream& inputFile) override;
};
#endif


