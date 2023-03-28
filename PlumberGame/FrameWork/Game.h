#ifndef __Game_H__
#define __Game_H__

class Game : public Chap
{
public:
	Game();
	~Game();
	
	float alpha;						//클리어, 오버 이미지 알파값
	float speed;						//알파값이 변환될 속도

	bool GameSet;						//게임 종료됐는가 판단
	
	Sprite Over;						//오버 효과 이미지 스프라이트
	Sprite Clear;						//클리어 효과 이미지 스프라이트
	Sprite Black;						//페이드 인에 사용할 검정색 배경
	Sprite Packing[3];					//게임 오버 시 맵을 덮어줄 이미지

	bool soundcheck;					//사운드가 한번만 나도록
	FILE *fp;

	DWORD GameTime;						//게임 제한 시간
	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);
};
#endif