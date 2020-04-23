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
	const int SCREEN_WIDTH = B_SIZE * 30 - (P_SIZE / 1.5);
	const int SCREEN_HEIGHT = B_SIZE * 20;
	
	// PATHS
	const string_t P_PLAYER = CSTRING("D:/Folders/Programming/C++/NeonPixel2D/resources/images/player.bmp");
	const string_t P_WALL   = CSTRING("D:/Folders/Programming/C++/NeonPixel2D/resources/images/wall.bmp");
	const string_t P_FLOOR  = CSTRING("D:/Folders/Programming/C++/NeonPixel2D/resources/images/floor.bmp");
}


namespace settings
{
	// COORDINATES 
	const int X(position_t position){return position.col * B_SIZE;}
	const int Y(position_t position){return position.line * B_SIZE;}
	
	const position_t MAKE_POSITION(const int x, const int y) 
	{
		return (const position_t){x, y};	
	}
	
	
	//TEXT
	const string_t CSTRING(const char* pString)
	{
		return(const string_t)pString;	
	}
	
	const string_t* CPSTRING(const char** pString)
	{
		return(const string_t*)pString;	
	}
}
