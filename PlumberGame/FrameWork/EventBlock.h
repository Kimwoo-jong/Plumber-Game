#pragma once
#include "Include.h"

class EventBlock
{
public:
    EventBlock(void);
    ~EventBlock(void);

    Sprite Time[10];                        //제한시간 이미지 스프라이트

    Sprite Start[4];                        //클리어 블럭 스프라이트 배열
    Sprite Start_Valve[4];                  //밸브 스프라이트

    Sprite Block;                           //장애물 이미지 스프라이트
    Sprite Soil;                            //흙 이미지 스프라이트

    DWORD valveAnim;                        //밸브 애니메이션 변수

    int valveCount;
    int clear_Count;                        //클리어 목표 저장

    bool isValveClick;                      //밸브를 클릭하였는가 판단
    bool clockCount = true;

    //장애물 배열 정보
    int block[3][3] = {
        2,2,2,
        2,0,2,
        2,2,2
    };

    //스타트 지점 배열 정보
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

    //클리어 배열 정보
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

    bool ClearCheck();                   //클리어 유무 체크하는 함수
};

extern EventBlock eventblock;