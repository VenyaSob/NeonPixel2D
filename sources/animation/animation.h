#include "../global/global.h"
using namespace global;


namespace animation
{	
	class CAnimation
	{
		private: 
			
			cstring_t  		    image;	
			counter_t 		    frame;
			const counter_t   n_frame;
			time_t 		  	     time;
			time_t		   FreqUpdate;
			bool 		 	     bRun;
			
		public:
			
			CAnimation(cstring_t image, const counter_t n_frame, time_t FreqUpdate):
			image(image), n_frame(n_frame), FreqUpdate(FreqUpdate), bRun(true) {}
			
			bool update(HDC hdc, position_t position);
			bool last_frame(HDC hdc, position_t position);
			void set_freq_update(time_t FreqUpdate);
			const time_t get_freq_update();
			bool run();
			bool start();
			bool stop();					
	};	
}

