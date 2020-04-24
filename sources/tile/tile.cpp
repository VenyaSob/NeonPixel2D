#include "tile.h"


namespace tile
{
	void DrawRecangle(HDC hdc, position_t position, HPEN hPen, HBRUSH hBrush)
	{
        SelectObject(hdc, hBrush);
        SelectObject(hdc, hPen);
       
        Rectangle(hdc, X(position), Y(position), X(position) + P_SIZE, Y(position) + P_SIZE);
   
        DeleteObject(hBrush);   
        DeleteObject(hPen);
	}	
	
	
	void SetImageBMP(HDC hdc, cstring_t image, coord_pair_t ulc, position_t position)
	{
        HANDLE    hBitmap, 
	    	   hOldBitmap;
   	    BITMAP	   Bitmap;	
		HDC hCompatibleDC;
		
		hBitmap = LoadImage(NULL, image, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        GetObject(hBitmap, sizeof(BITMAP), &Bitmap);
	    
		hCompatibleDC = CreateCompatibleDC(hdc);
	    hOldBitmap = SelectObject(hCompatibleDC, hBitmap);
	    
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
       	
		SelectObject(hCompatibleDC, hOldBitmap);
	    DeleteObject(hBitmap);
	    DeleteObject(hOldBitmap);
	    DeleteDC(hCompatibleDC);
	}
}
