#ifndef __SPRITE_H__													 
#define __SPRITE_H__


#include "../global/global.h"
using namespace global;


namespace sprite
{
	class CImageBMP
	{
		private: 
			
			cstring_t    path;
			HANDLE    hBitmap, 
				   hOldBitmap;
			BITMAP	   Bitmap;	
			HDC hCompatibleDC;
			HDC 		  hdc;
			bool 		bInit;
			
		public: 
			
			CImageBMP();
			CImageBMP(HDC hdc, cstring_t path);
			~CImageBMP();
		
		public: 
			
			bool init(HDC hdc, cstring_t path);
			void draw(HDC hdc, coord_pair_t ulc, position_t position);
			
	};
}


namespace sprite
{
	void DrawRecangle(HDC hdc, position_t position, HPEN hPen, HBRUSH hBrush);
}


#endif
