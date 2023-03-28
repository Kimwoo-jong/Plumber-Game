#pragma once
#include "Include.h"

class Map
{

public :
	Map();
	~Map();

	int clearTime;									//제한 시간

	//게임배경 이미지 스프라이트
	Sprite m_BackImg;
	Sprite Glass;
    Sprite soundIcon;
    Sprite exitButt;
    Sprite clock;

	int BackGround[29][29];							//게임보드 배열

	bool debug_Background;							//로직 검사용

	void Init();
	void Update(double frame);
	void Draw();
};

extern Map map;