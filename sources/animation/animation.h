#include "../global/global.h"
using namespace global;

#include "../sprite/sprite.h"
using namespace sprite;


namespace animation
{	
	class CAnimation
	{
		private: 
			
			CImageBMP 			image;
			cstring_t 		 	 path;
			counter_t 		    frame;
			const counter_t   n_frame;
			time_t 		  	     time;
			time_t		   FreqUpdate;
			bool 		 	     bRun;
			
		public:
			
			CAnimation(cstring_t path, const counter_t n_frame, time_t FreqUpdate):
			path(path), n_frame(n_frame), FreqUpdate(FreqUpdate), bRun(true) {}
			
		public:
			
			bool update(HDC hdc, position_t position);
			bool last_frame(HDC hdc, position_t position);
			void set_freq_update(time_t FreqUpdate);
			const time_t get_freq_update();
			bool run();
			bool start();
			bool stop();					
	};	
}

