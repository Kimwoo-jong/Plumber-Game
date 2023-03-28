#pragma once
#include "Include.h"

class Cursor
{
public:
	Cursor(void);
	~Cursor(void);

	Sprite cursorImg[3];		//Ŀ�� �̹���

	double cursor_X;			//Ŀ�� X ��ǥ
	double cursor_Y;			//Ŀ�� Y ��ǥ

	float cursorAngle;			//Ŀ���� ����

	bool isClick;				//Ŀ�� �ִϸ��̼ǿ� ����
	DWORD cursorAnim;

	void Init();
	void Update();
	void Draw();

	//���콺 �����̸� Ŀ���� ����ٴϵ��� �ϴ� �Լ�
	void ChasingCursorMove(LPARAM lParam);
};

extern Cursor cursor;