#include "../tile/tile.h"
using namespace tile;

#include "../animation/animation.h"
using namespace animation;

#include "map.h"


namespace 
{
	char szOldMap[20][30];	
}


namespace 
{	
	CAnimation anim(CSTRING("D:/Folders/Programming/C++/NeonPixel2D/resources/images/coin.bmp"), 8, MAKE_TIME(0.1));
}


namespace map
{		
	void Map(HDC hdc, action_t action)
	{		
		////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////
		
		static time_t b = 0.1;
		static int a = 0;
		static bool B = false;
		
		if(++a % 5 == 0)
		{	
			if(anim.get_freq_update() <= 0.01)
				B = true;
				
			if(!B) anim.set_freq_update(b -= 0.001);	
			else  
			{
				anim.set_freq_update(b += 0.001);		
				if(anim.get_freq_update() >= 0.1)
					B = false;
			}
		}
		
		////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////
			

	
		for(counter_t nLine = 0; nLine < M_SIZE_LINE; nLine++)	
		{
			for(counter_t nCol = 0; nCol < M_SIZE_COL; nCol++)
			{	
				if(szMap[nLine][nCol] == PLAYER)
				{
					anim.update(hdc, MAKE_POSITION(nLine, nCol));
				}
				
				if(szOldMap[nLine][nCol] != szMap[nLine][nCol] || action == recover)
				{	
					if(szMap[nLine][nCol] == PLAYER)
					{
						anim.last_frame(hdc, MAKE_POSITION(nLine, nCol));
					}
										
					if(szMap[nLine][nCol] == BLOCK)
					{
						SetImageBMP(hdc, P_FLOOR, MAKE_COORD_PAIR(0, 0), MAKE_POSITION(nLine, nCol));
					}
					
					if(szMap[nLine][nCol] == EMPT)
					{
						DrawRecangle(hdc, MAKE_POSITION(nLine, nCol), CreatePen(PS_SOLID, 1, 0), CreateSolidBrush(0));
						//SetImageBMP(hdc, P_FLOOR, MAKE_POSITION(nLine, nCol));
					}
					
					if(action != recover)
					{
						szOldMap[nLine][nCol] = szMap[nLine][nCol];	
					}
				}
			}	
		}	
	}
}

