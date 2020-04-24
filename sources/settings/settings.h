#include "../data type/data_type.h"
using namespace data_type;


namespace settings
{
	//TIMERS
	extern const int IDT_UPDATE_TIMER;
	extern const int IDT_BUSY_TIMER;
	
	//FERQ 
	extern const int FREQ_UPDATE_TIMER;
	
	//PLAYER
	extern const int P_SIZE;
	extern const int P_STEP;
	
	//BLOCK
	extern const int B_SIZE;
	
	//MAP
	extern const int M_SIZE_COL;
	extern const int M_SIZE_LINE;
	
	extern const int BLOCK;
	extern const int PLAYER;
	extern const int EMPT;
	
	//SCREEN SIZE
	extern const int SCREEN_WIDTH;
	extern const int SCREEN_HEIGHT;
	
	// PATHS
	extern cstring_t P_PLAYER;
	extern cstring_t P_WALL;
	extern cstring_t P_FLOOR;;
}


namespace settings
{	
	// COORDINATES 
	coord_t X(position_t position);
	coord_t Y(position_t position);
	
	position_t MAKE_POSITION(short line, short col); 
	coord_pair_t MAKE_COORD_PAIR(coord_t x, coord_t y);
	
	//TIME
	template <class template_data>
	time_t MAKE_TIME(template_data time)
	{
		return (time_t)time;	
	}
	
	//TEXT
	cstring_t CSTRING(const char* pString);
}
