#pragma once
#ifndef CCIRCLE_H
#define CCIRCLE_H
#include "CFigure.h"
class cCircle : public CFigure
{
private:
	Point point1;
	Point point2;
public:
	cCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool IsInside(int x, int y) const override;
	void Rotate90() override {};                     // Check if inside circle
	virtual void Swap(CFigure* fig) override;
	// Override the Swap method
	Point GetPosition1() const override;
	// Returns the first position of the circle
	Point GetPosition2() const override; // Returns the second position of the circle
	void SetPosition(Point p1, Point p2 = Point{ -1, -1 }, Point p3 = Point{ -1, -1 }) override;
	virtual CFigure* shiftlocation() const override;
	virtual void Save(std::ofstream& outFile) const override;
	virtual void Load(std::ifstream& inputFile) override;

};

#endif