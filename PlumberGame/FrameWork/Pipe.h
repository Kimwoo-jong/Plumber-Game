#pragma once
#include "Include.h"

class Pipe
{
public:
	Pipe(void);
	~Pipe(void);

	Sprite p_Pipe[4][4];							//������ �̹��� ��������Ʈ
	
	Sprite p_WaterAnim[4][4][4][3];					//�� �ִϸ��̼� ��������Ʈ
	Sprite p_WaterMove[4][4][4][3];					//�� �̹��� ��������Ʈ

	FILE *fp;

	//������ �̸����� �� ������ ����
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

	int type;										//������ Ÿ��
	int rotate_ok;									//���� �� �ִ°� ����
	int mouse;										//���콺�� �������� ��Ҵ°� ����

	double m_W;										//��Ʈ�� ������ ������ X ��ġ
	double m_H;										//��Ʈ�� ������ ������ Y ��ġ

	int rotateNum;									//���� Ƚ��

	bool isPipeUpCheck;								//�������� ���� �� �ִ°� ���� �Ǵ�

	//���� ���� ������ ���� ���� ����ü
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

	DWORD waterupdate;								//�� �帣�� �ð� ���� ����
	
	//���� ����ġ ���� ����ü
	struct Water
	{
		int i;
		int k;
	};
	Water water[50];

	int waterCount;								//���� �帣�� ���� �ִ°� ����   // 0 ���� // 1 ���� //
	int clear;									//Ŭ���� ����

	void Init();	
	void Update();
	void Draw();

	void Reset();								//����
	void PipeBack();							//������ ó�� ��ġ�� �ǵ�����
	void PipeCreate();

	void AddPipe(int kind, int back1, int back2, int rotate = 0, int type = 0);				//������ �迭�� ��׶��� �迭�� ����

	int PipeMouseUP(LPARAM lParam);															//���������� ���콺�� ���� ��

	void PipeMove(LPARAM lParam);															//�������� ��� ������ ��
	void ValveOn(LPARAM lParam);															//���긦 ������ ��
	void NowWaterCheck();																	//�帣�� �� üũ
	void WaterMove(int count);																//�������� ���� �� �� ĭ�� ����
	void WaterImgCheck();																	//�ش� ������ ��ġ�� ���� ������ ���� ���Դٰ� �˷��ִ� �Լ�
	
	int Type();																				//�������� Ÿ�� ���� Ȯ�� �Լ�

	void Load(int stage);																	//�������� �ε�

	// ������ Ÿ�Ժ� ������ �迭 ����
	int pipe_Block[4][4][3][3] = {
		//��
        2,1,2,
		2,1,2,
		2,1,2,
        //��
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
        //��
		2,1,2,
		2,1,1,
		2,1,2,
        //��
		2,2,2,
		1,1,1,
		2,1,2,
        //��
		2,1,2,
		1,1,2,
		2,1,2,
        //��
		2,1,2,
		1,1,1,
		2,2,2,

		/////
        //
		2,2,2,
		2,1,1,
		2,1,2,
        //��
		2,2,2,
		1,1,2,
		2,1,2,

		2,1,2,
		1,1,2,
		2,2,2,
        //��
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