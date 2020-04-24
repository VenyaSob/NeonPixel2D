#include "settings.h"


namespace settings
{
	//TIMERS
	const int IDT_UPDATE_TIMER = -0x999;
	const int IDT_BUSY_TIMER   = -0x998;
	
	//FERQ 
	const int FREQ_UPDATE_TIMER = 1;
	
	//PLAYER
	const int P_SIZE = 32; 
	const int P_STEP = P_SIZE;
	
	//BLOCK
	const int B_SIZE = P_SIZE;
	
	//MAP
	const int M_SIZE_LINE = 19;
	const int M_SIZE_COL  = 30;
	
	const int BLOCK  = '#';
	const int PLAYER = '*';
	const int EMPT   = (char)32;
	
	//SCREEN SIZE
	const int SCREEN_WIDTH  = B_SIZE * 30 - (P_SIZE / 1.5);
	const int SCREEN_HEIGHT = B_SIZE * 20;
	
	// PATHS
	cstring_t P_PLAYER = CSTRING("D:/Folders/Programming/C++/NeonPixel2D/resources/images/player.bmp");
	cstring_t P_WALL   = CSTRING("D:/Folders/Programming/C++/NeonPixel2D/resources/images/wall.bmp");
	cstring_t P_FLOOR  = CSTRING("D:/Folders/Programming/C++/NeonPixel2D/resources/images/floor.bmp");
}


namespace settings 	
{
	// COORDINATES 
	coord_t X(position_t position){return position.col * B_SIZE;}
	coord_t Y(position_t position){return position.line * B_SIZE;}
	
	position_t MAKE_POSITION(short line, short col) 
	{
		return (position_t){line, col};	
	}
	
	coord_pair_t MAKE_COORD_PAIR(coord_t x, coord_t y) 
	{
		return (coord_pair_t){x, y};	
	}
	
	
	//TEXT
	cstring_t CSTRING(const char* pString)
	{
		return(cstring_t)pString;	
	}
}
