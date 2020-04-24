#include "../global/global.h"
using namespace global;


namespace tile
{
	void DrawRecangle(HDC hdc, position_t position, HPEN hPen, HBRUSH hBrush);
	void SetImageBMP(HDC hdc, cstring_t image, coord_pair_t ulc, position_t position);
}
