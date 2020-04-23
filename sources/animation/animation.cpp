#include "animation.h"

#include "../tile/tile.h"
using namespace tile;


namespace animation
{		
	bool CAnimation::update(HDC hdc, time_t timer, position_t position)
	{
		if(bRun == true)
		{
			if(time >= (this->time + FreqUpdate))
			{
				if(frame > n_frame)
					frame = 0;
					
				SetImageBMP(hdc, pImage[frame], position);
				
				this->time = time;	
			}	
		}	
		
		return bRun;
	}
	
	
	bool CAnimation::start()
	{
		if(bRun == false)
			bRun = true;
		
		return bRun;	
	}
	
	
	bool CAnimation::stop()
	{
		if(bRun == true)
			bRun = false;
		
		return !bRun;			
	}
}


namespace animation
{		
	void neon_gradient(position_t position)
	{
		static double nTic = 70;
		
		if((nTic += 0.2) == 255) 
			nTic = 70;	 
		
		HDC hdc = GetDC(hWnd);	
		
		for(counter_t nX = 0; nX < B_SIZE; nX++)	
		{
			for(counter_t nY = 0; nY < B_SIZE; nY++)
			{
				SetPixel(hdc, X(position) + nX, Y(position) + nY, RGB(nX * nTic, sin(cos(nY * nTic)), nTic));
			}	
		}
		
		ReleaseDC(hWnd, hdc);
	}
}
