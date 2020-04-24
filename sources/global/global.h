#ifndef __GLOBAL_H__													 
#define __GLOBAL_H__

#include <winsock2.h>
#include <gdiplus.h>
using namespace Gdiplus;

#include "../settings/settings.h"
using namespace settings;

#include "../player/player.h"
using namespace player;

namespace stdio
{
	#include <stdio.h>
}

namespace global 
{
	extern HWND hWnd;
	
	extern time_t 		 time;
	extern CPlayer 	   Player;
	extern char szMap[20][30]; 
}


#endif


