#pragma once

class GameManager
{
public:
	GameManager(void);
	~GameManager(void);

	bool m_Pause;								//일시정지 (미구현) 현재는 도스 창이 나오면서 멈춤
	bool m_GameStart;							//게임 시작 여부 판단

	void GameReset();							//게임에서 처음에 한번만 초기화되는 부분

	void Init();
	void Update();
	void Draw();
};

extern GameManager Gmanager;