#pragma once
#include "Include.h"

Cursor cursor;

Cursor::Cursor(void)
{
	//Ŀ�� ��ǥ �ʱ�ȭ
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
	//���콺 Ŀ�� �̹��� ����
	for (int i = 0; i < 3; i++)
	{
		sprintf_s(FileName, "./resource/images/Cursur/spanner%d.png", i);
		cursorImg[i].Create(FileName,false,D3DCOLOR_XRGB(0,0,0));
	}
}

void Cursor::ChasingCursorMove(LPARAM lParam)
{
	//���� ��ġ���� ��¦ �밢 ��ġ
	cursor_X = LOWORD(lParam) - 10;
	cursor_Y = HIWORD(lParam) - 10;
}

void Cursor::Update()
{
	//�������� ��� ��Ŭ��
	if (isClick == true)
	{
		//������ ȸ��ȿ��
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
	//Ŀ���� �׷��ش�.
	cursorImg[0].Render(cursor_X, cursor_Y, cursorAngle * (D3DX_PI / 180.0f), 1, 1);
}

