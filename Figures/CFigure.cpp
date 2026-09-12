#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo) : FigGfxInfo(FigureGfxInfo), Selected(false)
{
	
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }


void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = false;
	FigGfxInfo.FillClr = Fclr; 
}
color CFigure::GetOriginalDrawColor() const
{
	return OriginalDrawColor;
}
color CFigure::GetOriginalFillColor() const
{
	return OriginalFillColor;
}

