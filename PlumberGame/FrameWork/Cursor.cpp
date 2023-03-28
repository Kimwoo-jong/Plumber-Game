#pragma once
#include "Include.h"

Cursor cursor;

Cursor::Cursor(void)
{
	//커서 좌표 초기화
	cursor_X = 0;
	cursor_Y = 0;
}

Cursor::~Cursor(void)
{
}

void Cursor::Init()
{
	cursorAngle = 0;
	isClick = false;

	char FileName[256];
	//마우스 커서 이미지 저장
	for (int i = 0; i < 3; i++)
	{
		sprintf_s(FileName, "./resource/images/Cursur/spanner%d.png", i);
		cursorImg[i].Create(FileName,false,D3DCOLOR_XRGB(0,0,0));
	}
}

void Cursor::ChasingCursorMove(LPARAM lParam)
{
	//실제 위치보다 살짝 대각 위치
	cursor_X = LOWORD(lParam) - 10;
	cursor_Y = HIWORD(lParam) - 10;
}

void Cursor::Update()
{
	//파이프를 잡고 우클릭
	if (isClick == true)
	{
		//파이프 회전효과
		if (GetTickCount() - cursorAnim > 10)
		{
			if (cursorAngle == 45)
			{
				cursorAngle = 315;
			}
			else if (cursorAngle >= 360)
			{
				cursorAngle = 0;
				isClick = false;
			}
			else
			{
				cursorAngle += 5;
			}
			cursorAnim = GetTickCount();
		}
	}
}

void Cursor::Draw()
{
	//커서를 그려준다.
	cursorImg[0].Render(cursor_X, cursor_Y, cursorAngle * (D3DX_PI / 180.0f), 1, 1);
}

