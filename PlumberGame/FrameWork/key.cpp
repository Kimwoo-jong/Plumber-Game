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
	//���� ���� Ȯ���� ���� ���ӽð� 15�� ġƮŰ
	if(KeyDown('1'))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			map.clearTime = 15;
			KeyTime = GetTickCount();
		}
	}
	//���� Ŭ���� Ȯ���� ���� ���ӽð� 100�� ġƮŰ
	if (KeyDown('3'))
	{
		if (GetTickCount() - KeyTime > 200)
		{
			map.clearTime = 100;
			KeyTime = GetTickCount();
		}
	}
	//���� ����׿�(�ʿ� ���ڸ� ����� �����ش�)
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
	//������ ȸ��
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
					//3�� ���� �� ���� �������
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