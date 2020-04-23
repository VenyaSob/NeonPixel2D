#include "../global/global.h"
using namespace global;


namespace animation
{
	class CAnimation
	{
		private: 
			
			const string_t  *pImage;	
			counter_t 		  frame;
			const counter_t n_frame;
			time_t 			   time;
			const time_t FreqUpdate;
			bool 		 	   bRun;
			
		public:
			
			CAnimation(const string_t *pImage, const counter_t n_frame, const time_t nFreqUpdate):
			pImage(pImage), n_frame(n_frame), FreqUpdate(FreqUpdate), bRun(true) {}
			
			bool update(HDC hdc, time_t time, position_t position);
			bool start();
			bool stop();					
	};	
}


namespace animation
{
	void neon_gradient(position_t position);	
}
