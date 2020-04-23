#include "tile.h"


namespace tile
{
	void DrawRectangle(HDC hdc, position_t position, HPEN hPen, HBRUSH hBrush)
	{
        SelectObject(hdc, hBrush);
        SelectObject(hdc, hPen);
       
        Rectangle(hdc, X(position), Y(position), X(position) + P_SIZE, Y(position) + P_SIZE);
   
        DeleteObject(hBrush);   
        DeleteObject(hPen);
	}	
	
	
	void SetImageBMP(HDC hdc, const char *pPath, position_t position)
	{
        HANDLE    hBitmap, 
	    	   hOldBitmap;
   	    BITMAP	   Bitmap;	
		HDC hCompatibleDC;
		
		hBitmap = LoadImage(NULL, pPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        GetObject(hBitmap, sizeof(BITMAP), &Bitmap);
	    
		hCompatibleDC = CreateCompatibleDC(hdc);
	    hOldBitmap = SelectObject(hCompatibleDC, hBitmap);
	    
		StretchBlt(hdc, X(position), Y(position), B_SIZE, B_SIZE, hCompatibleDC, 0, 0, Bitmap.bmWidth, 
       	Bitmap.bmHeight, SRCCOPY);
       	
		SelectObject(hCompatibleDC, hOldBitmap);
	    DeleteObject(hBitmap);
	    DeleteObject(hOldBitmap);
	    DeleteDC(hCompatibleDC);
	}
}
