#ifndef __Menu_H__
#define __Menu_H__

class Menu : public Chap
{
public:
	Menu();
	~Menu();

	Sprite mainImg;												//�޴� �̹���
	Sprite startImg;											//���� ��ư �̹���
	Sprite exitImg;												//���� ��ư �̹���
	Sprite helpImg;												//���� �̹���

	Sprite Stage[2][10];										//�������� �̹���
	Sprite StageBack[2];										//�������� ��� �̹���
	Sprite Black;												//���� ������ ��� ���� �̹���

	Sprite helpScreenImg;										//���� ���� �̹���

	int button_push[12];										//�������� ��ư ȿ�� ����

	int mouseOverStart;											//���� ��ư ȿ���� ����
	int mouseOverExit;											//���� ��ư ȿ���� ����
	int mouseOverHelp;											//���� ��ư ȿ���� ����
	
	bool isMute;												//���Ұ� ��ư�� ���ȴ°� �Ǵ�
	bool isHelpOn;												//���ھ� ���尡 �����ִ°� �Ǵ�
	bool isStageSelectOn;										//�������� ����â�� �����ִ°� �Ǵ�
	bool menuSoundCheck;										//�޴� ���� �� ���� ����ǵ���

	float helpImageSize;										//���� �̹��� ȿ���� ���� float ����

	//�������� ��ư ���콺 �Է¿�
	void StageMouseMove(LPARAM lParam);
	void StageMouseDown(LPARAM lParam);

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

}; extern Menu menu;

#endif