
namespace data_type
{	
	typedef int   	     counter_t;
	typedef double          time_t;
	typedef const char*  cstring_t;  
	typedef unsigned short coord_t;
	
	struct coord_pair_t
	{
		coord_t x;		
		coord_t y;
	};
	
	struct position_t
	{
		short line;		
		short  col;
	};
}
