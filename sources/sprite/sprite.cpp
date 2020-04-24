#include "sprite.h"


namespace sprite
{
	CImageBMP::CImageBMP(){}
	
	
	CImageBMP::CImageBMP(HDC hdc, cstring_t image): hdc(hdc), path(path)
	{	
		bInit = true;
		
		hBitmap = LoadImage(NULL, path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        GetObject(hBitmap, sizeof(BITMAP), &Bitmap);
	    
		hCompatibleDC = CreateCompatibleDC(hdc);
	    hOldBitmap = SelectObject(hCompatibleDC, hBitmap);		
	}
	
	
	CImageBMP::~CImageBMP()
	{
		SelectObject(hCompatibleDC, hOldBitmap);
	    DeleteObject(hBitmap);
	    DeleteObject(hOldBitmap);
	    DeleteDC(hCompatibleDC);
	}
	
	
	bool CImageBMP::init(HDC hdc, cstring_t path)
	{
		if(bInit == false)
		{
			this->hdc = hdc;
			this->path = path;	
			
			hBitmap = LoadImage(NULL, path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	        GetObject(hBitmap, sizeof(BITMAP), &Bitmap);
		    
			hCompatibleDC = CreateCompatibleDC(hdc);
		    hOldBitmap = SelectObject(hCompatibleDC, hBitmap);		
				
			bInit = true;
			return true;
		}
		else return false;
	}
	
	
	void CImageBMP::draw(HDC hdc, coord_pair_t ulc, position_t position)
	{
		StretchBlt(hdc, 
				   X(position), 
				   Y(position), 
				   B_SIZE, 
				   B_SIZE, 
				   hCompatibleDC, 
				   ulc.x, 
				   ulc.y, 
				   B_SIZE,
				   B_SIZE,
				   SRCCOPY);	
	}
}


namespace sprite
{
	void DrawRecangle(HDC hdc, position_t position, HPEN hPen, HBRUSH hBrush)
	{
        SelectObject(hdc, hBrush);
        SelectObject(hdc, hPen);
       
        Rectangle(hdc, X(position), Y(position), X(position) + P_SIZE, Y(position) + P_SIZE);
   
        DeleteObject(hBrush);   
        DeleteObject(hPen);
	}	
}
