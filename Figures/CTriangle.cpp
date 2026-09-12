#include "CTriangle.h"
#include <iostream>
using namespace std;

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
bool CTriangle::IsInside(int x, int y) const {
    auto Area = [](int x1, int y1, int x2, int y2, int x3, int y3) {
        return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
        };

    double A = Area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
    double A1 = Area(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
    double A2 = Area(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
    double A3 = Area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);

    return (A == A1 + A2 + A3); // Check if the sum of sub-areas equals the total area
}
void CTriangle::Rotate90() {
    // Calculate the center of the triangle
    int centerX = (Corner1.x + Corner2.x + Corner3.x) / 3;
    int centerY = (Corner1.y + Corner2.y + Corner3.y) / 3;

    // Rotate each corner 90 degrees around the center
    Corner1 = { centerX - (Corner1.y - centerY), centerY + (Corner1.x - centerX) };
    Corner2 = { centerX - (Corner2.y - centerY), centerY + (Corner2.x - centerX) };
    Corner3 = { centerX - (Corner3.y - centerY), centerY + (Corner3.x - centerX) };
}
void CTriangle::Swap(CFigure* fig) {
    Point temp1 = Corner1;
    Point temp2 = Corner2;
    Point temp3 = Corner3;
    Corner1 = fig->GetPosition1();
    Corner2 = fig->GetPosition2();
    Corner3 = fig->GetPosition3();
    fig->SetPosition(temp1, temp2, temp3);
}

Point CTriangle::GetPosition1() const {
    return Corner1;
}

Point CTriangle::GetPosition2() const {
    return Corner2;
}

Point CTriangle::GetPosition3() const {
    return Corner3;
}

void CTriangle::SetPosition(Point p1, Point p2, Point p3) {
    // Calculate the offsets for each corner
    int offsetX1 = Corner2.x - Corner1.x;
    int offsetY1 = Corner2.y - Corner1.y;
    int offsetX2 = Corner3.x - Corner1.x;
    int offsetY2 = Corner3.y - Corner1.y;

    // Set the new first corner
    Corner1 = p1;

    // Calculate the new second and third corners
    Corner2.x = Corner1.x + offsetX1;
    Corner2.y = Corner1.y + offsetY1;
    Corner3.x = Corner1.x + offsetX2;
    Corner3.y = Corner1.y + offsetY2;

    // make sure the triangle is in the draw area
    if (Corner1.x < 0 || Corner2.x < 0 || Corner3.x < 0) {
        int shiftX = max(0 - Corner1.x, max(0 - Corner2.x, 0 - Corner3.x));
        Corner1.x += shiftX;
        Corner2.x += shiftX;
        Corner3.x += shiftX;
    }
    if (Corner1.y < UI.ToolBarHeight || Corner2.y < UI.ToolBarHeight || Corner3.y < UI.ToolBarHeight) {
        int shiftY = max(UI.ToolBarHeight - Corner1.y, max(UI.ToolBarHeight - Corner2.y, UI.ToolBarHeight - Corner3.y));
        Corner1.y += shiftY;
        Corner2.y += shiftY;
        Corner3.y += shiftY;
    }
    if (Corner1.x > UI.width || Corner2.x > UI.width || Corner3.x > UI.width) {
        int shiftX = max(Corner1.x - UI.width, max(Corner2.x - UI.width, Corner3.x - UI.width));
        Corner1.x -= shiftX;
        Corner2.x -= shiftX;
        Corner3.x -= shiftX;
    }
    if (Corner1.y > UI.height - UI.StatusBarHeight || Corner2.y > UI.height - UI.StatusBarHeight || Corner3.y > UI.height - UI.StatusBarHeight) {
        int shiftY = max(Corner1.y - (UI.height - UI.StatusBarHeight), max(Corner2.y - (UI.height - UI.StatusBarHeight), Corner3.y - (UI.height - UI.StatusBarHeight)));
        Corner1.y -= shiftY;
        Corner2.y -= shiftY;
        Corner3.y -= shiftY;
    }
}
CFigure* CTriangle::shiftlocation() const {
    return new CTriangle(*this); // Use the copy constructor to create a new instance
}
void CTriangle::Save(std::ofstream& outFile) const {
    outFile << "Triangle " << Corner1.x << " " << Corner1.y << " "
        << Corner2.x << " " << Corner2.y << " "
        << Corner3.x << " " << Corner3.y << " ";
    outFile << FigGfxInfo.DrawClr.ucRed << " " << FigGfxInfo.DrawClr.ucGreen << " " << FigGfxInfo.DrawClr.ucBlue << " ";
    outFile << FigGfxInfo.isFilled << " ";
    if (FigGfxInfo.isFilled) {
        outFile << FigGfxInfo.FillClr.ucRed << " " << FigGfxInfo.FillClr.ucGreen << " " << FigGfxInfo.FillClr.ucBlue << " ";
    }
    outFile << FigGfxInfo.BorderWdth << " ";


}
void CTriangle::Load(std::ifstream& inputFile) {
    inputFile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
    inputFile >> FigGfxInfo.DrawClr.ucRed >> FigGfxInfo.DrawClr.ucGreen >> FigGfxInfo.DrawClr.ucBlue;
    inputFile >> FigGfxInfo.isFilled;
    if (FigGfxInfo.isFilled) {
        inputFile >> FigGfxInfo.FillClr.ucRed >> FigGfxInfo.FillClr.ucGreen >> FigGfxInfo.FillClr.ucBlue;
    }
    inputFile >> FigGfxInfo.BorderWdth;
}