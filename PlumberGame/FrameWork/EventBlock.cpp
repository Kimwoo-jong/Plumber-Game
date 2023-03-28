#pragma once
#include "Include.h"

EventBlock eventblock;

EventBlock::EventBlock(void)
{
}

EventBlock::~EventBlock(void)
{
}

bool EventBlock::ClearCheck()
{
    int count = 0;
    for (int i = 0; i < 29; i++)
    {
        for (int k = 0; k < 29; k++)
        {
            //�ش� �迭�� Ŭ���� üũ�� �Ǿ�������
            if (map.BackGround[i][k] == PP_CLEAR_CHECK)
            {
                //ī��Ʈ1 ����
                count++;
            }
        }
    }
    //Ŭ���� ��ǥ�� Ŭ���� üũ�� ������ ��ġ�ϸ� Ʈ��
    if (clear_Count == count)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void EventBlock::Init()
{
    valveCount = 0;
    isValveClick = false;

    clear_Count = 0;

    char FileName[256];

    for (int i = 0; i < 4; i++)
    {
        sprintf_s(FileName, "./resource/images/start/Start%02d.png", i);
        Start[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
    }

    for (int i = 0; i < 4; i++)
    {
        sprintf_s(FileName, "./resource/images/start/Valve%02d.png", i);
        Start_Valve[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
    }

    Block.Create("./resource/images/start/obs.png", false, D3DCOLOR_XRGB(0, 0, 0));
    Soil.Create("./resource/images/start/soil.png", false, D3DCOLOR_XRGB(0, 0, 0));

    for (int i = 0; i < 10; i++)
    {
        sprintf_s(FileName, "./resource/images/number/%d.png", i);
        Time[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
    }
}

void EventBlock::Update()
{
    if (Gmanager.m_GameStart == true)
    {
        //���갡 �����ٸ�
        if (isValveClick == true)
        {
            //���ư��� �ִϸ��̼�
            if (GetTickCount() - valveAnim > 100)
            {
                valveCount++;
                if (valveCount > 3) valveCount = 0;
                valveAnim = GetTickCount();
            }
        }
    }
}

void EventBlock::Draw()
{
    if (Gmanager.m_GameStart == true)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int k = 0; k < 9; k++)
            {
                if (pipe.save[i][k].isStart == false && pipe.save[i][k].isClear == false)
                {
                    Soil.Render((k * BLOCKSIZE + BACKSTART), (i * BLOCKSIZE + BACKSTART), 0, 1, 1);
                }
            }
        }
        for (int i = 0; i < 9; i++)
        {
            for (int k = 0; k < 9; k++)
            {
                //�ش� ��ġ�� ��ŸƮ �����̸� ��ŸƮ�̹����� �׷��ش�
                if (pipe.save[i][k].isStart == true)
                {
                    Start[pipe.save[i][k].rotate].Render((k * BLOCKSIZE + BACKSTART), (i * BLOCKSIZE + BACKSTART), 0, 1, 1);
                    Start_Valve[valveCount].Render((k * BLOCKSIZE + BACKSTART), (i * BLOCKSIZE + BACKSTART), 0, 1, 1);

                }
                //�ش� ��ġ�� Ŭ���� �����̸� Ŭ�����̹����� �׷��ش�
                else if (pipe.save[i][k].isClear == true)
                {
                    Start[pipe.save[i][k].rotate].Render((k * BLOCKSIZE + BACKSTART), (i * BLOCKSIZE + BACKSTART), 0, 1, 1);


                }
                //�ش� ��ġ�� ��ֹ��̸� ��ֹ��̹����� �׷��ش�
                else if (pipe.save[i][k].isBlock == true)
                {
                    Block.Render((k * BLOCKSIZE + BACKSTART), (i * BLOCKSIZE + BACKSTART), 0, 1, 1);
                }
            }
        }
        //���ѽð� �׷��ֱ�
        //�����ð��� �������� ���⸦ ����Ͽ� 10���ڸ��� 1���ڸ����� ���� �ش� �̹����� ���
        int temp, temp1, temp2, temp3;

        temp = map.clearTime; // 152

        temp1 = temp / 100; // 100�ڸ�
        temp2 = (temp - temp1 * 100) / 10; // 10�ڸ�
        temp3 = temp - temp1 * 100 - temp2 * 10; // 1�ڸ�

        Time[temp1].Render(804, 673, 0, 1, 1);
        Time[temp2].Render(836, 673, 0, 1, 1);
        Time[temp3].Render(868, 673, 0, 1, 1);
    }
}