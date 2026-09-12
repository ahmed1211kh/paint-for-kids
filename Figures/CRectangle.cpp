#include "CRectangle.h"
#include<iostream>
using namespace std;

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::IsInside(int x, int y) const {
	return (x >= Corner1.x && x <= Corner2.x && y >= Corner1.y && y <= Corner2.y); // Check if inside rectangle
}
void CRectangle::Rotate90() {
    // Calculate the center of the rectangle
 // Calculate the center of the triangle
	int centerX = (Corner1.x + Corner2.x) / 2;
	int centerY = (Corner1.y + Corner2.y) / 2;

	// Rotate each corner 90 degrees around the center
	Corner1 = { centerX - (Corner1.y - centerY), centerY + (Corner1.x - centerX) };
	Corner2 = { centerX - (Corner2.y - centerY), centerY + (Corner2.x - centerX) };
	for (int i = 0; i < 2; i++)
	{
	
		if (Corner1.x > Corner2.x)
		{
			swap(Corner1.x, Corner2.x);
		}
		if (Corner1.y > Corner2.y)
		{
			swap(Corner1.y, Corner2.y);
		}
	}
}
// Override the Swap method
void CRectangle::Swap(CFigure* fig) {
	// Ensure the other figure is also a rectangle
	CRectangle* otherRect = dynamic_cast<CRectangle*>(fig);
	if (otherRect) {
		std::swap(Corner1, otherRect->Corner1);
		std::swap(Corner2, otherRect->Corner2);
		std::swap(FigGfxInfo, otherRect->FigGfxInfo);
	}
}
Point CRectangle::GetPosition1() const {
	return Corner1; // Returns the first position of the rectangle
}
Point CRectangle::GetPosition2() const {
	return Corner2; // Returns the second position of the rectangle
}
void CRectangle::SetPosition(Point p1, Point p2, Point p3) {
	// Calculate the width and height of the rectangle
	int width = abs(Corner2.x - Corner1.x);
	int height = abs(Corner2.y - Corner1.y);

	// Set the  top-left corner
	Corner1 = p1;

	// Calculate the  bottom-right corner
	Corner2.x = Corner1.x + width;
	Corner2.y = Corner1.y + height;

	// make sure that the rectangle is   in the draw area
	if (Corner2.x > UI.width) {
		Corner1.x -= (Corner2.x - UI.width);
		Corner2.x = UI.width;
	}
	if (Corner2.y > UI.height - UI.StatusBarHeight) {
		Corner1.y -= (Corner2.y - (UI.height - UI.StatusBarHeight));
		Corner2.y = UI.height - UI.StatusBarHeight;
	}
	if (Corner1.x < 0) {
		Corner2.x += abs(Corner1.x);
		Corner1.x = 0;
	}
	if (Corner1.y < UI.ToolBarHeight) {
		Corner2.y += abs(Corner1.y - UI.ToolBarHeight);
		Corner1.y = UI.ToolBarHeight;
	}
}
CFigure* CRectangle::shiftlocation() const {
	return new CRectangle(*this); 
}
void CRectangle::Save(std::ofstream& outFile) const {
	outFile << "Rectangle " << Corner1.x << " " << Corner1.y << " "
		<< Corner2.x << " " << Corner2.y << " ";
	outFile << FigGfxInfo.DrawClr.ucRed << " " << FigGfxInfo.DrawClr.ucGreen << " " << FigGfxInfo.DrawClr.ucBlue << " ";
	outFile << FigGfxInfo.isFilled << " ";
	if (FigGfxInfo.isFilled) {
		outFile << FigGfxInfo.FillClr.ucRed << " " << FigGfxInfo.FillClr.ucGreen << " " << FigGfxInfo.FillClr.ucBlue << " ";
	}
	outFile << FigGfxInfo.BorderWdth << " ";



}
void CRectangle::Load(std::ifstream& inputFile) {
	inputFile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	inputFile >> FigGfxInfo.DrawClr.ucRed >> FigGfxInfo.DrawClr.ucGreen >> FigGfxInfo.DrawClr.ucBlue;
	inputFile >> FigGfxInfo.isFilled;
	if (FigGfxInfo.isFilled) {
		inputFile >> FigGfxInfo.FillClr.ucRed >> FigGfxInfo.FillClr.ucGreen >> FigGfxInfo.FillClr.ucBlue;
	}
	inputFile >> FigGfxInfo.BorderWdth;
}