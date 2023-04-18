#pragma once

#include "Include.h"

static DWORD KeyTime = GetTickCount();

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Init()
{
	mouseOverStart = 0;																	//시작 버튼 효과음 변수
	mouseOverExit = 0; 																	//종료 버튼 효과음 변수
	mouseOverHelp = 0; 																	//도움말 버튼 효과음 변수

	bool  muteChk = 0;
	isHelpOn = false; 																	//도움말 화면인가 체크
	isStageSelectOn = false; 															//스테이지 선택 화면인지
	helpImageSize = 0; 																	//도움말 창 사이즈는 0
	menuSoundCheck = false; 															//메뉴 효과음 한 번만 나게

	for (int i = 0; i < 12; i++)
	{
		button_push[i] = 0;
	}

	mainImg.Create("./resource/images/Menu/MAIN.png", false, D3DCOLOR_XRGB(0, 0, 0));			 //메인
	helpScreenImg.Create("./resource/images/score1111.png", false, D3DCOLOR_XRGB(0, 0, 0));		 //도움말 이미지

	char FileName[256];

	sprintf_s(FileName, "./resource/images/Menu/START1.png");								 //START버튼 이미지 객체 생성
	startImg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/images/Menu/EXIT1.png");								 //EXIT버튼 이미지
	exitImg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/images/Menu/help.png");									 //도움말 버튼 이미지
	helpImg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//스테이지 이미지
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 9; k++)
		{
			if (i == 0)
			{
				sprintf_s(FileName, "./resource/images/Stage/Stg_%d.png", k);
			}
			else
			{
				sprintf_s(FileName, "./resource/images/Stage/PStg_%d.png", k);
			}
			Stage[i][k].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
		}
	}

	Stage[0][9].Create("./resource/images/Stage/Stg_Custom.png", false, D3DCOLOR_XRGB(0, 0, 0));
	Stage[1][9].Create("./resource/images/Stage/PStg_Custom.png", false, D3DCOLOR_XRGB(0, 0, 0));
	StageBack[0].Create("./resource/images/Stage/Back.png", false, D3DCOLOR_XRGB(0, 0, 0));
	StageBack[1].Create("./resource/images/Stage/PBack.png", false, D3DCOLOR_XRGB(0, 0, 0));
	Black.Create("./resource/images/Stage/BlackBack.png", false, D3DCOLOR_XRGB(0, 0, 0));
}

void Menu::Update(double frame)
{
	//메뉴 사운드 출력
	if (menuSoundCheck == false)
	{
		if (isMute == 0)
		{
			sound.m_Menu->Reset();
			sound.m_Menu->Play(0, DSBPLAY_LOOPING);
			menuSoundCheck = true;
		}
		else
		{
			sound.m_Menu->Stop();
			menuSoundCheck = true;
		}
	}
	//메뉴에서 키입력 위함
	key.Update();
	
	//스코어 보드가 켜지면
	if (isHelpOn)
	{
		if (helpImageSize < 1)
		{
			//점점 커지게
			helpImageSize += 0.025;
		}
	}
	else
	{
		if (helpImageSize > 0)
		{
			//점점 작아지게
			helpImageSize -= 0.025;
		}
	}
}

void Menu::Draw()
{
	//이미지들을 출력해준다.
	mainImg.Render(0, 0, 0, 1, 1);
	helpImg.Render(0, 0, 0, 1, 1);
	startImg.Render(0, 0, 0, 1, 1);
	exitImg.Render(0, 0, 0, 1, 1);
	helpScreenImg.Render(0, 0, 0, helpImageSize, helpImageSize);

	//도움말 버튼 클릭 시
	if (isHelpOn == true)
	{
		helpScreenImg.Render(0, 0, 0, helpImageSize, helpImageSize);
	}
	// 스테이지 선택 창이 켜지면
	else if (isStageSelectOn == true)
	{
		//뒤에 흐려지는 이미지
		Black.Render(0, 0, 0, 1, 1);

		int buttonCount = 0;
		int stageCount = 1;

		//스테이지 버튼 출력
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (i == 2)
				{
					if (k == 0)
					{
						StageBack[button_push[buttonCount]].Render((k * Stage_X_P) + (k * Stage_X_Size) + Stage_X, (i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y, 0, 1, 1);
					}
					else if (k == 2)
					{
						Stage[button_push[buttonCount]][0].Render((k * Stage_X_P) + (k * Stage_X_Size) + Stage_X, (i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y, 0, 1, 1);
					}
					else if (k == 3)
					{
						Stage[button_push[buttonCount]][9].Render((k * Stage_X_P) + (k * Stage_X_Size) + Stage_X, (i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y, 0, 1, 1);
					}
				}
				else
				{
					Stage[button_push[buttonCount]][stageCount].Render((k * Stage_X_P) + (k * Stage_X_Size) + Stage_X, (i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y, 0, 1, 1);
					stageCount++;
				}
				buttonCount++;
			}
		}
	}
}
//스테이지 버튼에 관한 마우스 이벤트
void Menu::StageMouseMove(LPARAM lParam)
{
	int button = 1;

	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if ((k * Stage_X_P) + (k * Stage_X_Size) + Stage_X + Stage_X_Size > LOWORD(lParam) &&
				LOWORD(lParam) > (k * Stage_X_P) + (k * Stage_X_Size) + Stage_X &&
				(i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y + Stage_Y_Size > HIWORD(lParam) &&
				HIWORD(lParam) > (i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y && isMute == 0)  //마우스가 스테이지 버튼 안으로 들어갔으면
			{
				if (button >= 1 && button <= 8)
				{
					if (button_push[button - 1] == 0)
					{
						if (isMute == 0)
							sound.m_Menuon->Play(0);
						else
							sound.m_Menuon->Stop();
					}
					button_push[button - 1] = 1;
				}
				//뒤로가기
				else if (button == 11)
				{
					if (button_push[10] == 0)
					{
						if (isMute == 0)
							sound.m_Menuon->Play(0);
						else
							sound.m_Menuon->Stop();
					}
					button_push[10] = 1;
				}
				else if (button == 12)
				{
					if (button_push[11] == 0)
					{
						if (isMute == 0)
							sound.m_Menuon->Play(0);
						else
							sound.m_Menuon->Stop();
					}
					button_push[11] = 1;
				}
				else if (button == 9)
				{
					if (button_push[8] == 0)
					{
						if (isMute == 0)
							sound.m_Menuon->Play(0);
						else
							sound.m_Menuon->Stop();
					}
					button_push[8] = 1;
				}
			}
			//버튼에서 마우스 내려갔을 때
			else
			{
				if (button >= 1 && button <= 8)
				{
					if (button_push[button - 1] == 1)
					{
						if (isMute == 0)
							sound.m_Menuoff->Play(0);
						else
							sound.m_Menuoff->Stop();
					}
					button_push[button - 1] = 0;
				}
				else if (button == 11)
				{
					if (isMute == 0)
						sound.m_Menuoff->Play(0);
					else
						sound.m_Menuoff->Stop();
					button_push[10] = 0;
				}
				else if (button == 12)
				{
					if (button_push[11] == 1)
					{
						if (isMute == 0)
							sound.m_Menuoff->Play(0);
						else
							sound.m_Menuoff->Stop();
					}
					button_push[11] = 0;
				}
				else if (button == 9)
				{
					if (button_push[8] == 1)
					{
						if (isMute == 0)
							sound.m_Menuoff->Play(0);
						else
							sound.m_Menuoff->Stop();
					}
					button_push[8] = 0;
				}
			}
			button++;
		}
	}
}

void Menu::StageMouseDown(LPARAM lParam)
{
	int button = 1;
	//스테이지 버튼 클릭 시 사운드와 해당 스테이지 로드 후 넘어가기
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if ((k * Stage_X_P) + (k * Stage_X_Size) + Stage_X + Stage_X_Size > LOWORD(lParam) &&
				LOWORD(lParam) > (k * Stage_X_P) + (k * Stage_X_Size) + Stage_X &&
				(i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y + Stage_Y_Size > HIWORD(lParam) &&
				HIWORD(lParam) > (i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y)
			{
				if (button >= 1 && button <= 8)
				{
					pipe.Load(button);
					g_Mng.n_Chap = GAME;
					if (isMute == 0)
					{
						sound.m_Menusel->Play(0);
						sound.m_Menu->Stop();
						sound.m_Play->Reset();
						sound.m_Play->Play(0, DSBPLAY_LOOPING);
					}
					else
					{
						sound.m_Play->Stop();
						sound.m_Menu->Stop();
						sound.m_Menusel->Stop();
					}
				}
				else if (button == 11)
				{
					pipe.Load(0);
					g_Mng.n_Chap = GAME;
					if (isMute == 0)
					{
						sound.m_Menusel->Play(0);
						sound.m_Menu->Stop();
						sound.m_Play->Reset();
						sound.m_Play->Play(0, DSBPLAY_LOOPING);
					}
					else
					{
						sound.m_Play->Stop();
						sound.m_Menu->Stop();
						sound.m_Menusel->Stop();
					}
				}
				else if (button == 12)
				{
					pipe.Load(9);
					g_Mng.n_Chap = GAME;
					if (isMute == 0)
					{
						sound.m_Menusel->Play(0);
						sound.m_Menu->Stop();
						sound.m_Play->Reset();
						sound.m_Play->Play(0, DSBPLAY_LOOPING);
					}
					else
					{
						sound.m_Play->Stop();
						sound.m_Menu->Stop();
						sound.m_Menusel->Stop();
					}
				}
				else if (button == 9)
				{
					if (isMute == 0)
						sound.m_Menusel->Play(0);
					else
						sound.m_Menusel->Stop();

					isStageSelectOn = false;
				}
			}
			button++;
		}
	}
}

void Menu::OnMessage(MSG* msg)
{
	switch (msg->message)
	{
		//마우스가 메뉴버튼에 다가가면
	case WM_MOUSEMOVE:
		if (isHelpOn == false && isStageSelectOn == false)
		{
			//start 버튼 효과
			if (LOWORD(msg->lParam) >= 116 &&
				252 >= LOWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 515 &&
				602 > HIWORD(msg->lParam))
			{
				if (mouseOverStart == 0 && isMute == 0)
				{
					sound.m_Menuon->Play(0);
				}
				mouseOverStart = 1;
			}
			else
			{
				if (mouseOverStart == 1 && isMute == 0)
				{
					sound.m_Menuoff->Play(0);
				}
				mouseOverStart = 0;
			}

			//exit 버튼 효과
			if (950 >= LOWORD(msg->lParam) &&
				LOWORD(msg->lParam) >= 780 &&
				602 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 515)
			{
				if (mouseOverExit == 0 && isMute == 0)
				{
					sound.m_Menuon->Play(0);
				}
				mouseOverExit = 1;
			}
			else
			{
				if (mouseOverExit == 1 && isMute == 0)
				{
					sound.m_Menuoff->Play(0);
				}
				mouseOverExit = 0;
			}

			//설명 버튼 효과
			if (75 > LOWORD(msg->lParam) &&
				LOWORD(msg->lParam) >= 0 &&
				69 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 0)
			{
				if (mouseOverHelp == 0 && isMute == 0)
				{
					sound.m_Menuon->Play(0);
				}
				mouseOverHelp = 1;
			}
			else
			{
				if (mouseOverHelp == 1 && isMute == 0)
				{
					sound.m_Menuoff->Play(0);
				}
				mouseOverHelp = 0;
			}
		}
		else if (isStageSelectOn == true)
		{
			StageMouseMove(msg->lParam);
		}
		break;

		//메뉴 버튼을 클릭하면 게임 화면으로 넘어감
	case WM_LBUTTONDOWN:
		//음소거 버튼을 클릭 시
		if (1025 > LOWORD(msg->lParam) &&
			LOWORD(msg->lParam) >= 930 &&
			123 > HIWORD(msg->lParam) &&
			HIWORD(msg->lParam) >= 32)
		{
			if (isMute == 0)
				isMute = 1;
			else
				isMute = 0;

			if (isMute == 1)
			{
				sound.m_Menu->Stop();
			}
			else
			{
				sound.m_Menu->Play(0, DSBPLAY_LOOPING);
			}
		}
		if (isHelpOn == false && isStageSelectOn == false)
		{
			//start 버튼 누를 시
			if (LOWORD(msg->lParam) >= 116 &&
				252 >= LOWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 515 &&
				602 > HIWORD(msg->lParam))
			{
				//클릭 사운드와 함께 스테이지 선택창 켜줌
				if (isMute == 0)
				{
					sound.m_Menusel->Play(0);
				}
				else
				{
					sound.m_Menusel->Stop();
				}
				mouseOverStart = 0;
				g_Mng.chap[GAME]->Init();
				isStageSelectOn = true;
			}

			//exit 버튼 누를 시
			else if (950 >= LOWORD(msg->lParam) &&
				LOWORD(msg->lParam) >= 780 &&
				602 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 515)
			{
				if (isMute == 0)
				{
					sound.m_Menusel->Play(0);
				}
				else
				{
					sound.m_Menusel->Stop();
				}
				mouseOverExit = 0;

				PostQuitMessage(0);
			}

			//설명 버튼 누를 시
			else if (115 > LOWORD(msg->lParam) &&
				LOWORD(msg->lParam) >= 14 &&
				100 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 30)
			{
				//클릭 사운드와 함께 설명창 켜줌
				if (isMute == 0)
				{
					sound.m_Menusel->Play(0);
				}
				else
				{
					sound.m_Menusel->Stop();
				}
				isHelpOn = true;
			}
		}
		else if (isHelpOn == true)
		{
			if (isMute == 0)
				sound.m_Menusel->Play(0);
			else
				sound.m_Menusel->Stop();
			isHelpOn = false;
			mouseOverHelp = 0;
		}
		else if (isStageSelectOn == true)
		{
			StageMouseDown(msg->lParam);
		}
		break;
	}
}