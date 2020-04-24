#include "../global/global.h"
using namespace global;

#include "player.h"


namespace player
{
	void CPlayer::movement(act_t act)
	{	
		switch(act)
		{
			case forward: 
			{	
				if(szMap[position.line - 1][position.col] != BLOCK)
				{	
					szMap[position.line][position.col] = EMPT;
					szMap[position.line -= 1][position.col] = PLAYER;
				}
										
				break;
			}
		
			case back: 
			{
				if(szMap[position.line + 1][position.col] != BLOCK)
				{	
					szMap[position.line][position.col] = EMPT;
					szMap[position.line += 1][position.col] = PLAYER;				
				}
				
				break;
			}
			
			case left: 
			{
				if(szMap[position.line][position.col - 1] != BLOCK)
				{
					szMap[position.line][position.col] = EMPT;
					szMap[position.line][position.col -= 1] = PLAYER;
				}
				
				break;
			}
			
			case right: 
			{			
				if(szMap[position.line][position.col + 1] != BLOCK)
				{	
					szMap[position.line][position.col] = EMPT;
					szMap[position.line][position.col += 1] = PLAYER;
				}	
				
				break;
			}
		}
	}	
}


namespace player
{
	CPlayer::CPlayer()
	{
		for(counter_t nLine = 0; nLine < M_SIZE_LINE; nLine++)	
		{
			for(counter_t nCol = 0; nCol < M_SIZE_COL; nCol++)
			{
				if(szMap[nCol][nLine] == PLAYER)				
				{
					position = MAKE_POSITION(nCol, nLine);
				}
			}
		}	
	}		
}


namespace player
{	
	
	void CPlayer::perform(act_t act)	
	{
		if(act >= forward && act <= right) 
		{
			movement(act);
		}
	}
}

