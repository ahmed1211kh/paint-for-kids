#include "CSquare.h"

void cSquare::Draw(Output* pOut) const
{

    pOut->DrawSquare(center, FigGfxInfo, Selected);
}

cSquare::cSquare(Point center, int sidelength, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo) {
    this->center = center; // Store the center point of the square
    sideLength = 200;      // Set a default side length (adjust as needed)
}

bool cSquare::IsInside(int x, int y) const {
    // Calculate the bounds of the square based on the center and side length
    int halfSide = sideLength / 2;
    int left = center.x - halfSide;
    int right = center.x + halfSide;
    int top = center.y - halfSide;
    int bottom = center.y + halfSide;

    // Check if the point lies within the bounds
    return (x >= left && x <= right && y >= top && y <= bottom);
}
void cSquare::Swap(CFigure* fig) {
    // Ensure the other figure is also a square
    cSquare* otherSquare = dynamic_cast<cSquare*>(fig);
    if (otherSquare) {
        std::swap(center, otherSquare->center);
        std::swap(FigGfxInfo, otherSquare->FigGfxInfo);
    }
}
Point cSquare::GetPosition1() const {
    return center; // Returns the center position of the square

}
Point cSquare::GetPosition2() const {
    return Point{ -1, -1 }; // Optional second position
}
// Returns the second position of the square
void cSquare::SetPosition(Point p1, Point p2, Point p3) {
    center = p1; // Set the center position of the square
} // Set the position of the square


CFigure* cSquare::shiftlocation() const {
    return new cSquare(*this); // Use the copy constructor to create a new instance
}
void cSquare::Save(std::ofstream& outFile) const {
    outFile << "Square "
        << center.x << " " << center.y << " " << sideLength << " ";
    outFile << FigGfxInfo.DrawClr.ucRed << " " << FigGfxInfo.DrawClr.ucGreen << " " << FigGfxInfo.DrawClr.ucBlue << " ";
    outFile << FigGfxInfo.isFilled << " ";
    if (FigGfxInfo.isFilled) {
        outFile << FigGfxInfo.FillClr.ucRed << " " << FigGfxInfo.FillClr.ucGreen << " " << FigGfxInfo.FillClr.ucBlue << " ";
    }
    outFile << FigGfxInfo.BorderWdth << " ";


}
void cSquare::Load(std::ifstream& inputFile) {
    inputFile >> center.x >> center.y;
    inputFile >> FigGfxInfo.DrawClr.ucRed >> FigGfxInfo.DrawClr.ucGreen >> FigGfxInfo.DrawClr.ucBlue;
    inputFile >> FigGfxInfo.isFilled;
    if (FigGfxInfo.isFilled) {
        inputFile >> FigGfxInfo.FillClr.ucRed >> FigGfxInfo.FillClr.ucGreen >> FigGfxInfo.FillClr.ucBlue;
    }
    inputFile >> FigGfxInfo.BorderWdth;
}