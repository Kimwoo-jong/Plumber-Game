#pragma once
#include "Include.h"

class Map
{

public :
	Map();
	~Map();

	int clearTime;									//���� �ð�

	//���ӹ�� �̹��� ��������Ʈ
	Sprite m_BackImg;
	Sprite Glass;
    Sprite soundIcon;
    Sprite exitButt;
    Sprite clock;

	int BackGround[29][29];							//���Ӻ��� �迭

	bool debug_Background;							//���� �˻��

	void Init();
	void Update(double frame);
	void Draw();
};

extern Map map;