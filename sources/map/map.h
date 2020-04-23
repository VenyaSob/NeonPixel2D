#include "../global/global.h"
using namespace global;


namespace map
{
	enum action_t
	{
		draw,   
		recover	
	};
}


namespace map
{
	void Map(HDC hdc, action_t action);
}
