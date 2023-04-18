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
	mouseOverStart = 0;																	//���� ��ư ȿ���� ����
	mouseOverExit = 0; 																	//���� ��ư ȿ���� ����
	mouseOverHelp = 0; 																	//���� ��ư ȿ���� ����

	bool  muteChk = 0;
	isHelpOn = false; 																	//���� ȭ���ΰ� üũ
	isStageSelectOn = false; 															//�������� ���� ȭ������
	helpImageSize = 0; 																	//���� â ������� 0
	menuSoundCheck = false; 															//�޴� ȿ���� �� ���� ����

	for (int i = 0; i < 12; i++)
	{
		button_push[i] = 0;
	}

	mainImg.Create("./resource/images/Menu/MAIN.png", false, D3DCOLOR_XRGB(0, 0, 0));			 //����
	helpScreenImg.Create("./resource/images/score1111.png", false, D3DCOLOR_XRGB(0, 0, 0));		 //���� �̹���

	char FileName[256];

	sprintf_s(FileName, "./resource/images/Menu/START1.png");								 //START��ư �̹��� ��ü ����
	startImg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/images/Menu/EXIT1.png");								 //EXIT��ư �̹���
	exitImg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/images/Menu/help.png");									 //���� ��ư �̹���
	helpImg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	//�������� �̹���
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
	//�޴� ���� ���
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
	//�޴����� Ű�Է� ����
	key.Update();
	
	//���ھ� ���尡 ������
	if (isHelpOn)
	{
		if (helpImageSize < 1)
		{
			//���� Ŀ����
			helpImageSize += 0.025;
		}
	}
	else
	{
		if (helpImageSize > 0)
		{
			//���� �۾�����
			helpImageSize -= 0.025;
		}
	}
}

void Menu::Draw()
{
	//�̹������� ������ش�.
	mainImg.Render(0, 0, 0, 1, 1);
	helpImg.Render(0, 0, 0, 1, 1);
	startImg.Render(0, 0, 0, 1, 1);
	exitImg.Render(0, 0, 0, 1, 1);
	helpScreenImg.Render(0, 0, 0, helpImageSize, helpImageSize);

	//���� ��ư Ŭ�� ��
	if (isHelpOn == true)
	{
		helpScreenImg.Render(0, 0, 0, helpImageSize, helpImageSize);
	}
	// �������� ���� â�� ������
	else if (isStageSelectOn == true)
	{
		//�ڿ� ������� �̹���
		Black.Render(0, 0, 0, 1, 1);

		int buttonCount = 0;
		int stageCount = 1;

		//�������� ��ư ���
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
//�������� ��ư�� ���� ���콺 �̺�Ʈ
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
				HIWORD(lParam) > (i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y && isMute == 0)  //���콺�� �������� ��ư ������ ������
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
				//�ڷΰ���
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
			//��ư���� ���콺 �������� ��
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
	//�������� ��ư Ŭ�� �� ����� �ش� �������� �ε� �� �Ѿ��
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
		//���콺�� �޴���ư�� �ٰ�����
	case WM_MOUSEMOVE:
		if (isHelpOn == false && isStageSelectOn == false)
		{
			//start ��ư ȿ��
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

			//exit ��ư ȿ��
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

			//���� ��ư ȿ��
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

		//�޴� ��ư�� Ŭ���ϸ� ���� ȭ������ �Ѿ
	case WM_LBUTTONDOWN:
		//���Ұ� ��ư�� Ŭ�� ��
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
			//start ��ư ���� ��
			if (LOWORD(msg->lParam) >= 116 &&
				252 >= LOWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 515 &&
				602 > HIWORD(msg->lParam))
			{
				//Ŭ�� ����� �Բ� �������� ����â ����
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

			//exit ��ư ���� ��
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

			//���� ��ư ���� ��
			else if (115 > LOWORD(msg->lParam) &&
				LOWORD(msg->lParam) >= 14 &&
				100 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 30)
			{
				//Ŭ�� ����� �Բ� ����â ����
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