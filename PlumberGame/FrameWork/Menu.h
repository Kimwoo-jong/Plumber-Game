#ifndef __Menu_H__
#define __Menu_H__

class Menu : public Chap
{
public:
	Menu();
	~Menu();

	Sprite mainImg;												//메뉴 이미지
	Sprite startImg;											//시작 버튼 이미지
	Sprite exitImg;												//종료 버튼 이미지
	Sprite helpImg;												//도움말 이미지

	Sprite Stage[2][10];										//스테이지 이미지
	Sprite StageBack[2];										//스테이지 배경 이미지
	Sprite Black;												//게임 오버시 띄울 검정 이미지

	Sprite helpScreenImg;										//게임 설명 이미지

	int button_push[12];										//스테이지 버튼 효과 변수

	int mouseOverStart;											//시작 버튼 효과용 변수
	int mouseOverExit;											//종료 버튼 효과용 변수
	int mouseOverHelp;											//점수 버튼 효과용 변수
	
	bool isMute;												//음소거 버튼이 눌렸는가 판단
	bool isHelpOn;												//스코어 보드가 켜져있는가 판단
	bool isStageSelectOn;										//스테이지 선택창이 켜져있는가 판단
	bool menuSoundCheck;										//메뉴 사운드 한 번만 실행되도록

	float helpImageSize;										//설명 이미지 효과를 위한 float 변수

	//스테이지 버튼 마우스 입력용
	void StageMouseMove(LPARAM lParam);
	void StageMouseDown(LPARAM lParam);

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

}; extern Menu menu;

#endif