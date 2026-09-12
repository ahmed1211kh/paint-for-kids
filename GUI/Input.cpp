#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
	
			// Add more mappings...
		

		// Other mappings...
	
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	

			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			if (x >= 0 && x < 50) return SET_RED_COLOR;
			if (x >= 50 && x < 100) return SET_BLUE_COLOR;
			if (x >= 100 && x < 150) return SET_GREEN_COLOR;
			if (x >= 150 && x < 200) return SET_BLACK_COLOR;
			if (x >= 200 && x < 250) return SET_ORANGE_COLOR;
			if (x >= 300&& x < 350) return SET_YELLOW_COLOR;

			switch (ClickedItemOrder)
			{

			case ITM_RECT: return DRAW_RECT;
			case ITM_TRI: return DRAW_TRI;
			case ITM_EXIT: return EXIT;
			case ITM_SQR: return DRAW_SQR;
			case ITM_CIR: return DRAW_CIR;	
			case ITM_HEX: return DRAW_HEX;
			case SELECT: return SELECT_SHAPE;
			case TOGGLE: return TOGGLE_SHAPE;
			case ROTATE: return ROTATE_SHAPE;
			case dELETE: return DELETE_SHAPE;
			case CLEARALL : return ClEAR_SHAPE;
			case swaP:return SWAP_SHAPE;
			case COPY:return COPY_SHAPE;
			case PASTE:return PASTE_SHAPE;
			case CUT:return CUT_SHAPE;
			case SAVE:return SAVE_SHAPE;
			case LOAD:return LOAD_SHAPE;
			case TO_PLAY: return SWITCHTOPLAY;
			
		
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (UI.InterfaceMode == MODE_PLAY) {
			if (y >= 0 && y < UI.ToolBarHeight) {
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				
				switch (ClickedItemOrder)
				{
				case TO_DRAW:
					return SWITCHTODRAW;
				default: return EMPTY;
				}

			}
			if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			{
				return PLAYING_AREA;
			}












		}


		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return SWITCHTOPLAY;	//just for now. This should be updated
	}

}
/////////////////////////////////
	
Input::~Input()
{
}
