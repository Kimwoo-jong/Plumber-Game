#pragma once

#include "resource.h"
#include "Include.h" 
const int TICKS_PER_SECOND = 60;
const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
const int MAX_FRAMESKIP = 5;
int loops;
float interpolation;

char buffer[128] = { 0,0,0,0 };
char ch[3] = { 0,0,0 };
////////////////////////////////////
LRESULT CALLBACK WndProc(HWND g_hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	srand(time(NULL));
	MSG msg;
	WNDCLASSEX wc;
	HWND g_hWnd;
	wc.hInstance = GetModuleHandle(NULL);
	wc.cbSize = sizeof(wc);
	wc.style = CS_CLASSDC;
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(wc.hInstance, IDC_ARROW);
	wc.hIcon = LoadIcon(wc.hInstance, MAKEINTRESOURCE(101));
	wc.hIconSm = LoadIcon(wc.hInstance, MAKEINTRESOURCE(101));
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = "Game";
	wc.lpszMenuName = NULL;

	RegisterClassEx(&wc);

	/* ---------------------------------------------------
	/////////////////// 정가운데 출력 ////////////////////

				프로그램을 모니터의 정가운데
				출력하게 해 주는 코드입니다.

	//////////////////////////////////////////////////////
	----------------------요-기-서-부-터-----------------*/
	RECT rt = { 0, 0, SCREEN_WITH, SCREEN_HEIGHT };
	int W = rt.right - rt.left;
	int H = rt.bottom - rt.top;
	int X = (GetSystemMetrics(SM_CXSCREEN) / 2) - SCREEN_WITH / 2;
	int Y = ((GetSystemMetrics(SM_CYSCREEN) / 2) - SCREEN_HEIGHT / 2);
	/*---------------------요-기-까-지-------------------*/

	g_hWnd = CreateWindowEx(NULL, wc.lpszClassName,
		"Plumber Game",
		WS_OVERLAPPEDWINDOW,
		X, Y, W, H,
		GetDesktopWindow(), NULL, wc.hInstance, NULL);

	dv_font.Create(g_hWnd);
	sound.g_pSoundManager = new CSoundManager();
	sound.g_pSoundManager->Initialize(g_hWnd, DSSCL_PRIORITY);
	sound.g_pSoundManager->SetPrimaryBufferFormat(2, 22050, 16);

	ShowWindow(g_hWnd, SW_SHOW);
	UpdateWindow(g_hWnd);
	ShowCursor(FALSE);

	///////////////////////////////////////////////////////////////////
	ZeroMemory(&msg, sizeof(MSG));
	/////////// 챕터 초기화 /////////////////
	g_Mng.chap[LOGO] = new Logo;
	g_Mng.chap[MENU] = new Menu;
	g_Mng.chap[GAME] = new Game;
	g_Mng.chap[OVER] = new Over;
	/////////////////////////////////////////

	for (int i = 0; i < TOTALCHAP; i++)
		g_Mng.chap[i]->Init();

	cursor.Init();														//커서
	sound.Init();														//사운드

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
				g_Mng.chap[g_Mng.n_Chap]->OnMessage(&msg);
			}
		}
		else
		{
			static DWORD next_game_tick = GetTickCount();

			loops = 0;

			static int aa;
			bool b = false;

			while (GetTickCount() > next_game_tick && loops < MAX_FRAMESKIP)
			{
				interpolation = float(GetTickCount() + SKIP_TICKS - next_game_tick) / float(SKIP_TICKS);
				/*if(Gmanager.m_Pause == false)*/ g_Mng.chap[g_Mng.n_Chap]->Update(interpolation);
				cursor.Update();
				if (b == false)
				{
					aa = interpolation;
					b = true;
				}
				next_game_tick += SKIP_TICKS;
				loops++;
			}
			dv_font.Device9->BeginScene();
			dv_font.Device9->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 0, 0);

			g_Mng.chap[g_Mng.n_Chap]->Draw();
			cursor.Draw();

			dv_font.Device9->EndScene();
			dv_font.Device9->Present(NULL, NULL, NULL, NULL);
		}
	}
	return msg.wParam;

}

LRESULT CALLBACK WndProc(HWND g_hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	TCHAR str[128] = { 0 };
	POINTS pp;
	switch (uMsg)
	{
	case WM_GETMINMAXINFO:
		// 크기고정
		((MINMAXINFO*)lParam)->ptMaxTrackSize.x = 1064;

		((MINMAXINFO*)lParam)->ptMaxTrackSize.y = 803;

		((MINMAXINFO*)lParam)->ptMinTrackSize.x = 1064;

		((MINMAXINFO*)lParam)->ptMinTrackSize.y = 803;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_MOUSEMOVE:
		//커서가 마우스를 따라다니도록
		cursor.ChasingCursorMove(lParam);
		pp = MAKEPOINTS(lParam);
		
		//lParam에서 한꺼번에받은 마우스좌표가 x, y로 나뉨.
		sprintf(str, "x = %d, y = %d", pp.x, pp.y);
		
		SetWindowText(g_hWnd, str);
		break;
	}
	return DefWindowProc(g_hWnd, uMsg, wParam, lParam);
}