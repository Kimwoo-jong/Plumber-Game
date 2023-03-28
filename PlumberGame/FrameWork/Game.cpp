#define _CRT_NONSTDC_NO_DEPRECATE
#pragma once

#include "Include.h"
Menu menu;

Game::Game()
{

}

Game::~Game()
{

}

void Game::Init()
{
	speed = 1700;
	alpha = 0;
	soundcheck = false;

	GameSet = false;

	char FileName[256];
	Over.Create("./resource/images/Over/over.png", false, D3DCOLOR_XRGB(0, 0, 0));
	Clear.Create("./resource/images/Over/clear.png", false, D3DCOLOR_XRGB(0, 0, 0));
	Black.Create("./resource/images/Over/black.png", false, D3DCOLOR_XRGB(0, 0, 0));

	for (int i = 0; i < 3; i++)
	{
		sprintf_s(FileName, "./resource/images/Over/w00_00_00_%02d.png", i);
		Packing[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	map.Init();
	pipe.Init();
	Gmanager.Init();
	eventblock.Init();
}

void Game::Draw()
{
	map.Draw();
	eventblock.Draw();
	Gmanager.Draw();
	pipe.Draw();

	if (GameSet == true)
	{
		Black.Draw(0, 0);

		if (pipe.clear == 1)
		{
			Clear.SetColor(255, 255, 255, alpha);	//색상 변경
			Clear.Draw(0, 0);
		}
		else if (pipe.clear == 0)
		{
			for (int i = 0; i < 29; i++)			//용암으로 덮기
			{
				for (int j = 0; j < 29; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						if (i > 1 && i < 29 && j > 1 && j < 29)
						{
							map.BackGround[j][i] = Packing[k].Render((j * BLOCKSIZE + BACKSTART) / 3, (i * BLOCKSIZE + BACKSTART) / 3, 0, 1, 1);
						}

					}

				}
			}
			Over.SetColor(255, 255, 255, alpha);
			Over.Draw(0, 0);
		}
	}

	char asd[10];

	//백그라운드 배열 보여주는용도
	if (map.debug_Background == true)
	{
		for (int i = 0; i < 29; i++)
		{
			for (int k = 0; k < 29; k++)
			{
				_itoa(map.BackGround[i][k], asd, 10);
				dv_font.DrawString(asd, k * 21 + 83, i * 21 + 75);
			}
		}
	}
}

void Game::Update(double frame)
{
	key.Update();
	pipe.Update();
	eventblock.Update();
	map.Update(frame);
	Gmanager.Update();

	if (map.clearTime == 10)
	{
		if (menu.isMute == 0)
		{
			sound.m_Alert->Play(0);
			sound.m_Clock->Reset();
			sound.m_Clock->Play(0, DSBPLAY_LOOPING);
		}
		else
			sound.m_Alert->Stop();
		sound.m_Clock->Stop();
	}

	if (eventblock.isValveClick == false)					//스타트 하지 않았을 시
	{
		if (GetTickCount() - GameTime > 1000)			//1초마다 제한시간 1씩 감소
		{
			map.clearTime--;
			if (map.clearTime == 0)						//0초가 되면 함수 강제 스타트
			{
				if (menu.isMute == 0)
				{
					sound.m_Clock->Stop();
					sound.m_Play->Stop();
					sound.m_Valve->Play(0);
					sound.m_Water->Reset();
					sound.m_Water->Play(0, DSBPLAY_LOOPING);
				}
				else
				{
					sound.m_Clock->Stop();
					sound.m_Play->Stop();
					sound.m_Valve->Stop();
					sound.m_Water->Reset();
					sound.m_Water->Stop();
				}
				pipe.PipeBack();
				eventblock.isValveClick = true;
				pipe.isPipeUpCheck = false;
			}
			GameTime = GetTickCount();
		}
	}

	if (pipe.waterCount == 1)							//진행중인 오브젝트가 없을때
	{
		sound.m_Alert->Stop();
		sound.m_Clock->Stop();
		sound.m_Play->Stop();
		sound.m_Water->Stop();

		//클리어했을 시
		if (eventblock.ClearCheck() == true)
		{
			if (soundcheck == false)
			{
				if (menu.isMute == 0)
				{
					sound.m_Clear->Play(0);
					pipe.clear = 1;
					soundcheck = true;
				}
				else
					soundcheck = false;
			}
		}
		//클리어가 아니라면
		else
		{
			if (soundcheck == false)
			{
				if (menu.isMute == 0)
				{
					sound.m_Over->Play(0);
					soundcheck = true;
				}
				else
					soundcheck = false;
			}
		}
		GameSet = true;

		if (GameSet == true)
		{
			eventblock.clockCount = true;
		}
		//이미지 페이드 효과
		alpha += speed * frame / 1000;

		if (alpha >= 255)
		{
			alpha = 255;
			speed = -speed;
			Draw();
		}
		//이미지가 사라졌다면
		if (alpha <= 0)
		{
			//메뉴로 이동
			g_Mng.chap[MENU]->Init();
			g_Mng.n_Chap = MENU;
		}
	}
}

void Game::OnMessage(MSG* msg)
{
	switch (msg->message)
	{
	case WM_LBUTTONDOWN:
		if (Gmanager.m_GameStart == true && pipe.isPipeUpCheck == true)
		{
			//음소거 버튼을 눌렀을 때
			if (1025 > LOWORD(msg->lParam) &&
				LOWORD(msg->lParam) >= 930 &&
				123 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 32)
			{
				if (menu.isMute == 0)
				{
					menu.isMute = 1;
					sound.m_Play->Stop();
				}
				else
				{
					menu.isMute = 0;
					sound.m_Play->Play(0, DSBPLAY_LOOPING);
				}
			}
			//시계 아이템을 눌렀을 때
			else if (1023 > LOWORD(msg->lParam) &&
				LOWORD(msg->lParam) >= 943 &&
				747 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 673 && eventblock.clockCount == true)
			{
				pipe.mouse = 1;
				map.clearTime += 30;
				eventblock.clockCount = false;
			}
			//나가기 버튼을 눌렀을 때
			else if (900 > LOWORD(msg->lParam) &&
				LOWORD(msg->lParam) >= 803 &&
				123 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 32)
			{
				eventblock.clockCount = true;
				g_Mng.chap[MENU]->Init();
				g_Mng.n_Chap = MENU;
			}
			// 컨트롤이 가능한 파이프를 눌럿을 때
			if (pipe.m_W + 64 > LOWORD(msg->lParam) &&
				LOWORD(msg->lParam) >= pipe.m_W &&
				pipe.m_H + 64 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= pipe.m_H)
			{
				if (menu.isMute == 0)
					sound.m_PipePick->Play(0);
				else
					sound.m_PipePick->Stop();
				pipe.mouse = 1;

			}
			//밸브를 눌렀을 때
			else
			{
				pipe.ValveOn(msg->lParam);
			}
			break;
		}
	case WM_LBUTTONUP:
		if (Gmanager.m_GameStart == true && pipe.isPipeUpCheck == true)
		{
			if (pipe.mouse == 1)
			{
				//파이프가 놓여졋을떄
				if (pipe.PipeMouseUP(msg->lParam) == 1)
				{
					if (menu.isMute == 0)
						sound.m_PipeSet->Play(0);
					else
						sound.m_PipeSet->Stop();
					pipe.Reset();
				}
				else
				{
					//원래 자리에 다시 돌려놓는다
					if (menu.isMute == 0)
						sound.m_PipeWlong->Play(0);
					else
						sound.m_PipeWlong->Stop();
					pipe.PipeBack();
				}

			}
		}
		break;
	case WM_RBUTTONDOWN:
		if (Gmanager.m_GameStart == true && pipe.isPipeUpCheck == true)
		{
			for (int i = 0; i < 9; i++)
			{
				for (int k = 0; k < 9; k++)
				{
					// 블럭을 놓을수잇는 공간에 들어가잇을떄 
					if ((k * BLOCKSIZE + BACKSTART) + BLOCKSIZE > LOWORD(msg->lParam) &&
						LOWORD(msg->lParam) > (k * BLOCKSIZE + BACKSTART) &&
						(i * BLOCKSIZE + BACKSTART) + BLOCKSIZE > HIWORD(msg->lParam) &&
						HIWORD(msg->lParam) > (i * BLOCKSIZE + BACKSTART))
					{
						if (pipe.save[i][k].isStart == false && pipe.save[i][k].isClear == false)
						{
							pipe.mouse = 1;
							//eventblock.bSoil = false;
						}
					}
				}
			}
		}
		if (pipe.mouse == 1)
		{
			//커서 이미지 회전
			cursor.isClick = true;

			//파이프 회전
			if (pipe.type == 3)
			{
				pipe.rotateNum = 0;
			}
			else if (pipe.rotateNum == 3)
			{
				pipe.rotateNum = 0;
			}
			else
			{
				pipe.rotateNum++;
			}
			//회전용 사운드 출력
			if (menu.isMute == 0)
				sound.m_PipeRotate->Play(0);
			else
				sound.m_PipeRotate->Stop();
		}
		break;
	case WM_MOUSEMOVE:

		if (Gmanager.m_GameStart == true && pipe.isPipeUpCheck == true)
		{
			//파이프를 집었다.
			if (pipe.mouse == 1)
			{
				//파이프가 마우스를 따라 움직이도록 설정
				pipe.PipeMove(msg->lParam);
			}
		}
		break;
	}
}