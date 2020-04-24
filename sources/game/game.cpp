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
		time += (FREQ_UPDATE_TIMER / 50.0);
			
		hdc = GetDC(hWnd);
		Map(hdc, draw);
		ReleaseDC(hWnd, hdc);
		
		
		/////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////
		hdc = GetDC(hWnd);
		char text_buf[256];
		stdio::sprintf(text_buf, "game-time = %.6lf", global::time);
		TextOut(hdc, 10, 10, text_buf, 20);
		ReleaseDC(hWnd, hdc);
		/////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////
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

