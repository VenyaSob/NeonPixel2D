#include "animation.h"

#include "../tile/tile.h"
using namespace tile;


namespace animation
{	
	bool CAnimation::update(HDC hdc, position_t position)
	{	
		if(bRun == true)
		{
			if(global::time >= (this->time + FreqUpdate))
			{			
				if(frame > n_frame)
					frame = 0;
				
				SetImageBMP(hdc, image, MAKE_COORD_PAIR(frame * B_SIZE, 0), position);
			
				frame++;	
		
				this->time = global::time;
				return true;
			}
		}	
		
		return false;
	}
	
	
	bool CAnimation::last_frame(HDC hdc, position_t position)
	{ 	
		if(bRun == true)
		{	
			SetImageBMP(hdc, image, MAKE_COORD_PAIR(frame * B_SIZE, 0), position);	
		}
		
		return bRun;	
	}
	
	
	void CAnimation::set_freq_update(time_t FreqUpdate)
	{
		this->FreqUpdate = FreqUpdate;	
	}
	
	
	const time_t CAnimation::get_freq_update()
	{
		return FreqUpdate;	
	}
	

	bool CAnimation::run()
	{
		return bRun;	
	}
	
	
	bool CAnimation::start()
	{
		if(bRun == false)
		{	
			bRun = true;
			return true;
		}
		else return false;	
	}
	
	
	bool CAnimation::stop()
	{
		if(bRun == true)
		{	
			bRun = false;
			return true;
		}	
		else return false;
	}
}

