#ifndef __Logo_H__
#define __Logo_H__

class Logo : public Chap
{
public:
	Logo();
	~Logo();

	HWND hWnd;

	Sprite logoImage;							//로고 이미지 출력

	bool isIntroSoundOn;						//인트로가 재생되고 있는가

	float speed;
	float alpha;

	int count = 0;
	char cnt[256];
	char pw[256];

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);
};

#endif