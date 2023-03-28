#pragma once

class GameManager
{
public:
	GameManager(void);
	~GameManager(void);

	bool m_Pause;								//�Ͻ����� (�̱���) ����� ���� â�� �����鼭 ����
	bool m_GameStart;							//���� ���� ���� �Ǵ�

	void GameReset();							//���ӿ��� ó���� �ѹ��� �ʱ�ȭ�Ǵ� �κ�

	void Init();
	void Update();
	void Draw();
};

extern GameManager Gmanager;