#ifndef __PLAYER_H__													 
#define __PLAYER_H__


namespace player
{
	enum act_t 
	{
		nothing,
		forward,
		back   ,  
		left   ,  
		right  ,
		shot  
	};
}


namespace player
{
	class CPlayer 
	{
		private: 
	
			HDC             hdc;
			position_t position;
			
		private:
			
			void movement(act_t act);
			
		public:
			
			CPlayer();
			void perform(act_t act);		
	};
}


#endif

