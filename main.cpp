#include "sources/game/game.h"


LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) 
{	
	switch(Message) 
	{	
		case WM_CREATE:
		{ 
			game::Start();
			break;	
		}
		
		case WM_KEYDOWN:
		{	
			//set_neon_gradient((pos_t){1, 1});
			game::KeyboardHandler(wParam); 
			break;
		}
		
		case WM_PAINT: 
		{	
			game::Redraw(); 
			break;
		}
		
		case WM_CLOSE: 
		{ 
			DestroyWindow(hwnd);
			break;
		}
	
		case WM_DESTROY: 
		{
			PostQuitMessage(0);
			break;
		}
		
		default: return DefWindowProc(hwnd, Message, wParam, lParam);
	}

	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	WNDCLASSEX wc;
	MSG 	  Msg;

	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; 
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 3);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); 
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc)) 
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, "WindowClass", "Caption", WS_VISIBLE | WS_OVERLAPPEDWINDOW 
	    & ~WS_THICKFRAME 
		& ~WS_MAXIMIZEBOX,
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
	  	SCREEN_WIDTH, 
		SCREEN_HEIGHT, 
		NULL, NULL, hInstance, NULL);

	if(hWnd == NULL) 
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	while(GetMessage(&Msg, NULL, 0, 0) > 0) 
	{
		TranslateMessage(&Msg); 
		DispatchMessage(&Msg); 
	}
	
	return Msg.wParam;
}
