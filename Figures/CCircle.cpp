#include"CCircle.h"

cCircle::cCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	point1 = P1;
	point2 = P2;
}
void cCircle::Draw(Output* pOut) const
{
    GfxInfo HighlightedGfxInfo = FigGfxInfo;
    if (IsSelected()) {
        HighlightedGfxInfo.DrawClr = color(255, 0, 255); // Magenta color for highlight
    }
    pOut->DrawCir(point1, point2, FigGfxInfo, Selected);
}
bool cCircle::IsInside(int x, int y) const {
	// Calculate the radius of the circle
	int radius = sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));

	// Calculate the distance from the center (point1) to the point (x, y)
	int distanceSquared = pow(x - point1.x, 2) + pow(y - point1.y, 2);

	// Check if the distance is less than or equal to the radius squared
	return distanceSquared <= (radius * radius);
}
void cCircle::Swap(CFigure* fig) {
    // Ensure the other figure is also a circle
    cCircle* otherCircle = dynamic_cast<cCircle*>(fig);
    if (otherCircle) {
        std::swap(point1, otherCircle->point1);
        std::swap(point2, otherCircle->point2);
        std::swap(FigGfxInfo, otherCircle->FigGfxInfo);

    }
}
Point cCircle::GetPosition1() const {
    return point1; // Returns the first position of the circle
}
Point cCircle::GetPosition2() const {
    return point2; // Returns the second position of the circle
}
void cCircle::SetPosition(Point p1, Point p2, Point p3) {
    // Calculate the radius of the circle
    int radius = sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));

    //  the new center
    point1 = p1;

    //  the new curve point
    point2.x = point1.x + radius;
    point2.y = point1.y;

    // to make sure  the circle  in draw area
    if (point1.x - radius < 0) {
        point1.x += abs(point1.x - radius);
        point2.x = point1.x + radius;
    }
    if (point1.y - radius < UI.ToolBarHeight) {
        point1.y += abs(point1.y - radius - UI.ToolBarHeight);
        point2.y = point1.y;
    }
    if (point1.x + radius > UI.width) {
        point1.x -= (point1.x + radius - UI.width);
        point2.x = point1.x + radius;
    }
    if (point1.y + radius > UI.height - UI.StatusBarHeight) {
        point1.y -= (point1.y + radius - (UI.height - UI.StatusBarHeight));
        point2.y = point1.y;
    }
}
CFigure* cCircle::shiftlocation() const {
    return new cCircle(*this); 
}
void cCircle::Save(std::ofstream& outFile) const {
    outFile << "Circle " << point1.x << " " << point1.y << " "
        << point2.x << " " << point2.y << " "
        << FigGfxInfo.DrawClr.ucRed << " " << FigGfxInfo.DrawClr.ucGreen << " " << FigGfxInfo.DrawClr.ucBlue << " "
        << FigGfxInfo.isFilled << " ";
    if (FigGfxInfo.isFilled) {
        outFile << FigGfxInfo.FillClr.ucRed << " " << FigGfxInfo.FillClr.ucGreen << " " << FigGfxInfo.FillClr.ucBlue << " ";
    }
    outFile << FigGfxInfo.BorderWdth << std::endl;
}
void cCircle::Load(std::ifstream& inputFile) {
    inputFile >> point1.x >> point1.y >> point2.x >> point2.y;
    inputFile >> FigGfxInfo.DrawClr.ucRed >> FigGfxInfo.DrawClr.ucGreen >> FigGfxInfo.DrawClr.ucBlue;
    inputFile >> FigGfxInfo.isFilled;
    if (FigGfxInfo.isFilled) {
        inputFile >> FigGfxInfo.FillClr.ucRed >> FigGfxInfo.FillClr.ucGreen >> FigGfxInfo.FillClr.ucBlue;
    }
    inputFile >> FigGfxInfo.BorderWdth;
}