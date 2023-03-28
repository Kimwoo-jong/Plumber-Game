#pragma once
#include "Include.h"

Map map;

Map::Map()
{
}

Map::~Map()
{
}

void Map::Init()
{
	//클리어타임 초기화 (추후 에디터에서 설정)
	clearTime = 81;
	
	//게임보드 배열 초기화
	for (int i = 0; i < 29; i++)
	{
		for (int k = 0; k < 29; k++)
		{
			if (i == 0|| i == 28 || k == 0 || k == 28)
			{
				BackGround[i][k] = PP_WALL;
			}
			else
			{
				BackGround[i][k] = PP_EMPTY;
			}
		}
	}
	m_BackImg.Create("./resource/images/Background.png", false, D3DCOLOR_XRGB(0, 0, 0));
	Glass.Create("./resource/images/Glass.png", false, D3DCOLOR_XRGB(0, 0, 0));
    soundIcon.Create("./resource/images/sound.png", false, D3DCOLOR_XRGB(0, 0, 0));
    exitButt.Create("./resource/images/exit.png", false, D3DCOLOR_XRGB(0, 0, 0));
    clock.Create("./resource/images/clock.png", false, D3DCOLOR_XRGB(0, 0, 0));
}

void Map::Update(double frame)
{
}

void Map::Draw()
{
	m_BackImg.Render(0, 0, 0, 1, 1);
    Glass.Render(0,0,0,1,1);
    soundIcon.Render(0,0,0,1,1);
    exitButt.Render(0,0,0,1,1);
    clock.Render(0,0,0,1,1);
}