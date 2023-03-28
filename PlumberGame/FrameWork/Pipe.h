#pragma once
#include "Include.h"

class Pipe
{
public:
	Pipe(void);
	~Pipe(void);

	Sprite p_Pipe[4][4];							//파이프 이미지 스프라이트
	
	Sprite p_WaterAnim[4][4][4][3];					//물 애니메이션 스프라이트
	Sprite p_WaterMove[4][4][4][3];					//물 이미지 스프라이트

	FILE *fp;

	//파이프 미리보기 값 설정용 변수
	int type1;
	double H_type1;
	int rotate1;

	int type2;
	double H_type2;
	int rotate2;

	int type3;
	double H_type3;
	int rotate3;

	double W_type;

	int type;										//파이프 타입
	int rotate_ok;									//돌릴 수 있는가 여부
	int mouse;										//마우스로 파이프를 잡았는가 여부

	double m_W;										//컨트롤 가능한 파이프 X 위치
	double m_H;										//컨트롤 가능한 파이프 Y 위치

	int rotateNum;									//돌린 횟수

	bool isPipeUpCheck;								//파이프를 집을 수 있는가 여부 판단

	//내려 놓은 파이프 정보 저장 구조체
	struct pipedrawsave
	{
		bool isPipe;
		int type;
		int rotate;
		bool isWater;
		bool WaterMax;
		int MaxWaterCount;
		int WaterCount;
		int WaterMoveCount;
		bool isStart;
		bool isClear;
		int water_In;
		bool isBlock;
		
	};
	pipedrawsave save[9][9];

	DWORD waterupdate;								//물 흐르는 시간 조절 변수
	
	//현재 물위치 저장 구조체
	struct Water
	{
		int i;
		int k;
	};
	Water water[50];

	int waterCount;								//현재 흐르는 물이 있는가 여부   // 0 있음 // 1 없음 //
	int clear;									//클리어 정보

	void Init();	
	void Update();
	void Draw();

	void Reset();								//리셋
	void PipeBack();							//파이프 처음 위치로 되돌리기
	void PipeCreate();

	void AddPipe(int kind, int back1, int back2, int rotate = 0, int type = 0);				//파이프 배열을 백그라운드 배열에 적용

	int PipeMouseUP(LPARAM lParam);															//파이프에서 마우스를 뗐을 때

	void PipeMove(LPARAM lParam);															//파이프를 들고 움직일 때
	void ValveOn(LPARAM lParam);															//벨브를 눌럿을 때
	void NowWaterCheck();																	//흐르는 물 체크
	void WaterMove(int count);																//파이프를 따라 물 한 칸씩 전진
	void WaterImgCheck();																	//해당 파이프 위치에 물이 들어오면 물이 들어왔다고 알려주는 함수
	
	int Type();																				//파이프의 타입 등장 확률 함수

	void Load(int stage);																	//스테이지 로드

	// 파이프 타입별 각도별 배열 정보
	int pipe_Block[4][4][3][3] = {
		//ㅣ
        2,1,2,
		2,1,2,
		2,1,2,
        //ㅡ
		2,2,2,
		1,1,1,
		2,2,2,

		2,1,2,
		2,1,2,
		2,1,2,

		2,2,2,
		1,1,1,
		2,2,2,

		/////
        //ㅏ
		2,1,2,
		2,1,1,
		2,1,2,
        //ㅜ
		2,2,2,
		1,1,1,
		2,1,2,
        //ㅓ
		2,1,2,
		1,1,2,
		2,1,2,
        //ㅗ
		2,1,2,
		1,1,1,
		2,2,2,

		/////
        //
		2,2,2,
		2,1,1,
		2,1,2,
        //ㄱ
		2,2,2,
		1,1,2,
		2,1,2,

		2,1,2,
		1,1,2,
		2,2,2,
        //ㄴ
		2,1,2,
		2,1,1,
		2,2,2,

		/////
        //+
		2,1,2,
		1,1,1,
		2,1,2,

		2,1,2,
		1,1,1,
		2,1,2,

		2,1,2,
		1,1,1,
		2,1,2,

		2,1,2,
		1,1,1,
		2,1,2
	};
	
};

extern Pipe pipe;