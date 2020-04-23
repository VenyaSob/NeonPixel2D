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
	extern const string_t P_PLAYER;
	extern const string_t P_WALL;
	extern const string_t P_FLOOR;
}


namespace settings
{	
	// COORDINATES 
	const int X(position_t position);
	const int Y(position_t position);
	const position_t MAKE_POSITION(const int x, const int y);	
	
	//TEXT
	const string_t CSTRING(const char* pString);
	const string_t* CPSTRING(const char** pString);
}
