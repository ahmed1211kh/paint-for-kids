#include "Output.h"
#define root3 1.17


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	

	UI.width = 1350;
	UI.height = 700;
	UI.wx = 5;
	UI.wy = 5;

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 77;
	UI.LineUnderTBWidth = 2;
	UI.MenuItemWidth = 69;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = ORANGE;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	
	// Draw all figures
	
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
void Output::cleardrawtoolbar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight - UI.LineUnderTBWidth);
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	UI.MenuItemWidth = 50;
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[COLORRED] = "images\\MenuItems\\RED.jpg";
	MenuItemImages[COLORNBLUE] = "images\\MenuItems\\BLUE.jpg";
	MenuItemImages[COLORGREEN] = "images\\MenuItems\\GREEN.jpg";
	MenuItemImages[COLORBLACK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[COLORORANGE] = "images\\MenuItems\\orange.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[COLORYELLOW] = "images\\MenuItems\\yellow.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_SQR] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImages[ITM_CIR] = "images\\MenuItems\\Menu_Circle.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Menu_Hexagon.jpg";
	MenuItemImages[SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[TOGGLE] = "images\\MenuItems\\fill.jpg";
	MenuItemImages[ROTATE] = "images\\MenuItems\\Menu_Rotate.jpg";
	MenuItemImages[dELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[CLEARALL] = "images\\MenuItems\\Menu_ClearAll.jpg";
	MenuItemImages[swaP] = "images\\MenuItems\\Menu_Swap.jpg";
	MenuItemImages[COPY] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[PASTE] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[CUT] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuItemImages[SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[TO_PLAY] = "images\\MenuItems\\Menu_SwitchGame.jpg";


	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	UI.MenuItemWidth = 50;
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[TO_DRAW] = "images\\MenuItems\\Menu_Undo.jpg";
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::SetCrntDrawColor(color Dclr) {
	CrntDrawColor = Dclr;
	UI.DrawColor = Dclr; // Update the current drawing color
}
color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	
}
void Output::DrawSquare(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	int* px;
	int* py;
	// 4 ia the number of verticies
	px = new int[4];
	py = new int[4];

	//100 is the length of the square

	px[0] = P1.x + 100; py[0] = P1.y + 100;
	px[1] = P1.x + 100; py[1] = P1.y - 100;
	px[2] = P1.x - 100; py[2] = P1.y - 100;
	px[3] = P1.x - 100; py[3] = P1.y + 100;


	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawPolygon(px, py, 4, style);
	
}
void Output::DrawCir(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	int R = sqrt(((P1.x - P2.x) * (P1.x - P2.x)) + ((P1.y - P2.y) * (P1.y - P2.y)));//getting the Radius
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, R, style);
	
}
void Output::DrawHex(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	int* px;
	int* py;
	px = new int[6];
	py = new int[6];// 4 ia the number of verticies

	//100 is the length of the hexagon

	px[0] = P1.x + 100; py[0] = P1.y + 0;
	px[1] = P1.x + 50;  py[1] = P1.y + 50 * root3;
	px[2] = P1.x - 50;  py[2] = P1.y + 50 * root3;
	px[3] = P1.x - 100; py[3] = P1.y + 0;
	px[4] = P1.x - 50;  py[4] = P1.y - 50 * root3;
	px[5] = P1.x + 50; py[5] = P1.y - 50 * root3;


	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawPolygon(px, py, 6, style);
	
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output() {
	// Release any resources managed by the Output class
	delete pWind; // Assuming pWind is dynamically allocated
	pWind = nullptr;
}

