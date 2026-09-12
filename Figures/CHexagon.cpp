#include"CHexagon.h"
using namespace std;
#include <cmath> // For sqrt function
#define Pi 3.14159265358979323846
#include <iostream>
cHexagon::cHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	point1 = P1;
    int radius = 100; // Fixed radius for the hexagon
    for (int i = 0; i < 6; i++) {
        double angle = i * Pi / 3; // 60 degrees in radians
        Vertices[i].x = point1.x + radius * cos(angle);
        Vertices[i].y = point1.y + radius * sin(angle);
    }

}

void cHexagon::Draw(Output* pOut) const
{

	pOut->DrawHex(point1, FigGfxInfo, Selected);
}
bool cHexagon::IsInside(int x, int y) const {
    // Calculate the distance from the center to the point
    int dx = x - point1.x; // point1 is the center of the hexagon
    int dy = y - point1.y;
    double distance = sqrt(dx * dx + dy * dy);

    // The radius of the hexagon is the distance from the center to any vertex
    double radius = 100; // Assuming a fixed radius (adjust based on your implementation)

    // Check if the point is within the radius
    return distance <= radius;
}
void cHexagon::Rotate90() {
    // The center of the hexagon is already defined as point1
    int centerX = point1.x;
    int centerY = point1.y;

    // Rotate each vertex 90 degrees around the center
    // Rotate each vertex 90 degrees around the center
    for (int i = 0; i < 6; i++) {
        int oldX = Vertices[i].x;
        int oldY = Vertices[i].y;

        // Apply 90-degree rotation transformation
        Vertices[i].x = centerX - (oldY - centerY);
        Vertices[i].y = centerY + (oldX - centerX);
    }
}
void cHexagon::Swap(CFigure* fig) {
    // Ensure the other figure is also a hexagon
    cHexagon* otherHex = dynamic_cast<cHexagon*>(fig);
    if (otherHex) {
        std::swap(point1, otherHex->point1);
        std::swap(FigGfxInfo, otherHex->FigGfxInfo);
    }
}
Point cHexagon::GetPosition1() const {
    return point1; // get the first position of the hexagon
}
Point cHexagon::GetPosition2() const {
    return Point{ -1, -1 }; // get second position
}
void cHexagon::SetPosition(Point p1, Point p2, Point p3) {
    point1 = p1; // Set the position of the hexagon
} 

CFigure* cHexagon::shiftlocation() const {
    return new cHexagon(*this); 
}

void cHexagon::Save(std::ofstream& outFile) const {
    outFile << "Hexagon " << point1.x << " " << point1.y << " ";
    outFile << FigGfxInfo.DrawClr.ucRed << " " << FigGfxInfo.DrawClr.ucGreen << " " << FigGfxInfo.DrawClr.ucBlue << " ";
    outFile << FigGfxInfo.isFilled << " ";
    if (FigGfxInfo.isFilled) {
        outFile << FigGfxInfo.FillClr.ucRed << " " << FigGfxInfo.FillClr.ucGreen << " " << FigGfxInfo.FillClr.ucBlue << " ";
    }
    outFile << FigGfxInfo.BorderWdth << " ";
}
void cHexagon::Load(std::ifstream& inputFile) {
    inputFile >> point1.x >> point1.y;
    inputFile >> FigGfxInfo.DrawClr.ucRed >> FigGfxInfo.DrawClr.ucGreen >> FigGfxInfo.DrawClr.ucBlue;
    inputFile >> FigGfxInfo.isFilled;
    if (FigGfxInfo.isFilled) {
        inputFile >> FigGfxInfo.FillClr.ucRed >> FigGfxInfo.FillClr.ucGreen >> FigGfxInfo.FillClr.ucBlue;
    }
    inputFile >> FigGfxInfo.BorderWdth;
}