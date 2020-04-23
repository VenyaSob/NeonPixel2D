#include "../global/global.h"
using namespace global;


namespace tile
{
	void DrawRecangle(HDC hdc, position_t position, HPEN hPen, HBRUSH hBrush);
	void SetImageBMP(HDC hdc, const char *pPath, position_t position);
}
