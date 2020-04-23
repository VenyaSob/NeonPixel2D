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
	const char *images[] = {"D:/Folders/Programming/C++/NeonPixel2D/resources/images/wall.bmp", 
						    "D:/Folders/Programming/C++/NeonPixel2D/resources/images/player.bmp"};
	
	CAnimation anim_player(CPSTRING(images), 2, 1);
	
	time_t time;	
}


namespace map
{		
	void Map(HDC hdc, action_t action)
	{
		time += (FREQ_UPDATE_TIMER / 1000);
					
		for(counter_t nLine = 0; nLine < M_SIZE_LINE; nLine++)	
		{
			for(counter_t nCol = 0; nCol < M_SIZE_COL; nCol++)
			{	
				if(szMap[nLine][nCol] == PLAYER)
				{
					anim_player.update(hdc, ::time, MAKE_POSITION(nLine, nCol));
					//SetImageBMP(hdc, P_PLAYER, POS(nLine, nCol));
					//neon_gradient(POS);
				}
				
				if(szOldMap[nLine][nCol] != szMap[nLine][nCol] || action == recover)
				{	
					
					if(szMap[nLine][nCol] == BLOCK)
					{
						SetImageBMP(hdc, P_WALL, MAKE_POSITION(nLine, nCol));
					}
					
					if(szMap[nLine][nCol] == EMPT)
					{
						SetImageBMP(hdc, P_FLOOR, MAKE_POSITION(nLine, nCol));
					}
					/*						
					switch(szMap[nLine][nCol])
					{											
						case BLOCK: 
						{	
							SetImageBMP(hdc, P_WALL, position(nLine, nCol));	
							break;
						}
						
						case EMPT:
						{
							SetImageBMP(hdc, P_FLOOR, position(nLine, nCol));	
							break;	
						}
					}*/	
					
					if(action != recover)
					{
						szOldMap[nLine][nCol] = szMap[nLine][nCol];	
					}
				}
			}	
		}	
	}
}

