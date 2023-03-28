#pragma once
#include "Include.h"

class EventBlock
{
public:
    EventBlock(void);
    ~EventBlock(void);

    Sprite Time[10];                        //���ѽð� �̹��� ��������Ʈ

    Sprite Start[4];                        //Ŭ���� �� ��������Ʈ �迭
    Sprite Start_Valve[4];                  //��� ��������Ʈ

    Sprite Block;                           //��ֹ� �̹��� ��������Ʈ
    Sprite Soil;                            //�� �̹��� ��������Ʈ

    DWORD valveAnim;                        //��� �ִϸ��̼� ����

    int valveCount;
    int clear_Count;                        //Ŭ���� ��ǥ ����

    bool isValveClick;                      //��긦 Ŭ���Ͽ��°� �Ǵ�
    bool clockCount = true;

    //��ֹ� �迭 ����
    int block[3][3] = {
        2,2,2,
        2,0,2,
        2,2,2
    };

    //��ŸƮ ���� �迭 ����
    int start[4][3][3] = {
        2,3,2,
        2,2,2,
        2,2,2,

        2,2,2,
        2,2,3,
        2,2,2,

        2,2,2,
        2,2,2,
        2,3,2,

        2,2,2,
        3,2,2,
        2,2,2
    };

    //Ŭ���� �迭 ����
    int clear[4][3][3] = {
        2,6,2,
        2,2,2,
        2,2,2,

        2,2,2,
        2,2,6,
        2,2,2,

        2,2,2,
        2,2,2,
        2,6,2,

        2,2,2,
        6,2,2,
        2,2,2
    };

    void Init();
    void Update();
    void Draw();

    bool ClearCheck();                   //Ŭ���� ���� üũ�ϴ� �Լ�
};

extern EventBlock eventblock;