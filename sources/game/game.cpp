#include "game.h"

#include "../map/map.h"
using namespace map;


namespace
{
	HDC 				hdc;	
	PAINTSTRUCT paintstruct; 
}



namespace
{ 		
	void update()
	{
		hdc = GetDC(hWnd);
		Map(hdc, draw);
		ReleaseDC(hWnd, hdc);
	}	
}


namespace game
{
	void Start()
	{		
		SetTimer(hWnd, IDT_UPDATE_TIMER, FREQ_UPDATE_TIMER, (TIMERPROC)update);
	}
	
	
	void KeyboardHandler(WPARAM KeyPressed)
	{
		switch(KeyPressed)
		{
			case VK_UP:    Player.perform(forward); break;	
			case VK_LEFT:  Player.perform(left);    break;
			case VK_RIGHT: Player.perform(right);   break;
			case VK_DOWN:  Player.perform(back);    break;
		}	
	}	
	
	
	void Redraw()
	{		
		hdc = BeginPaint(hWnd, &paintstruct);
		Map(hdc, recover);	
		EndPaint(hWnd, &paintstruct);
	}
}

