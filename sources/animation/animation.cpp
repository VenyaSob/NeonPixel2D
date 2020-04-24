#include "animation.h"


namespace animation
{	 
	bool CAnimation::update(HDC hdc, position_t position)
	{	
		static counter_t cnt_init;
		if(++cnt_init == 1)
		{
			image.init(hdc, path);	
		}
		
		if(bRun == true)
		{
			if(global::time >= (this->time + FreqUpdate))
			{			
				if(frame > n_frame)
					frame = 0;
				
				image.draw(hdc, MAKE_COORD_PAIR(frame * B_SIZE, 0), position);
		
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
			image.draw(hdc, MAKE_COORD_PAIR(frame * B_SIZE, 0), position);
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

