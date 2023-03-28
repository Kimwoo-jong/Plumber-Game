#pragma once
#include "Include.h"

Key key;

Key::Key(void)
{

}

Key::~Key(void)
{

}

void Key::Update()
{
	//게임 오버 확인을 위한 게임시간 15초 치트키
	if(KeyDown('1'))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			map.clearTime = 15;
			KeyTime = GetTickCount();
		}
	}
	//게임 클리어 확인을 위한 게임시간 100초 치트키
	if (KeyDown('3'))
	{
		if (GetTickCount() - KeyTime > 200)
		{
			map.clearTime = 100;
			KeyTime = GetTickCount();
		}
	}
	//로직 디버그용(맵에 숫자를 띄워서 보여준다)
	if (KeyDown('5'))
	{
		if (GetTickCount() - KeyTime > 200)
		{
			if (map.debug_Background == true)
			{
				map.debug_Background = false;
			}
			else if (map.debug_Background == false)
			{
				map.debug_Background = true;
			}
			KeyTime = GetTickCount();
		}
	}	
	//파이프 회전
	if(KeyDown(VK_SPACE) )
	{	
		if(GetTickCount() - KeyTime2 > 200)
		{
			if (Gmanager.m_GameStart == true)
			{
				if (pipe.rotate_ok == 1)
				{
					if (pipe.type == 3)
					{
						pipe.rotateNum = 0;
					}
					//3번 돌릴 시 원래 모습으로
					else if (pipe.rotateNum == 3)
					{
						pipe.rotateNum = 0;
					}
					else
					{
						pipe.rotateNum++;
					}
				}
			}		
			KeyTime2 = GetTickCount();
		}	
	}
}