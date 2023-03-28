#pragma once
#include "Include.h"

class Cursor
{
public:
	Cursor(void);
	~Cursor(void);

	Sprite cursorImg[3];		//커서 이미지

	double cursor_X;			//커서 X 좌표
	double cursor_Y;			//커서 Y 좌표

	float cursorAngle;			//커서의 각도

	bool isClick;				//커서 애니메이션용 변수
	DWORD cursorAnim;

	void Init();
	void Update();
	void Draw();

	//마우스 움직이면 커서가 따라다니도록 하는 함수
	void ChasingCursorMove(LPARAM lParam);
};

extern Cursor cursor;