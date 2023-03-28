#ifndef __Game_H__
#define __Game_H__

class Game : public Chap
{
public:
	Game();
	~Game();
	
	float alpha;						//Ŭ����, ���� �̹��� ���İ�
	float speed;						//���İ��� ��ȯ�� �ӵ�

	bool GameSet;						//���� ����ƴ°� �Ǵ�
	
	Sprite Over;						//���� ȿ�� �̹��� ��������Ʈ
	Sprite Clear;						//Ŭ���� ȿ�� �̹��� ��������Ʈ
	Sprite Black;						//���̵� �ο� ����� ������ ���
	Sprite Packing[3];					//���� ���� �� ���� ������ �̹���

	bool soundcheck;					//���尡 �ѹ��� ������
	FILE *fp;

	DWORD GameTime;						//���� ���� �ð�
	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);
};
#endif