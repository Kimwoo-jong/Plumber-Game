#pragma once
#include "Include.h"


class Test
{



public:
	Test(void);
	~Test(void);

	Sprite testimg[20];

	double t_W;
	double t_H;


	DWORD testani1;
	
	int testcount;




	void Init();
	void Update();
	void Draw();


};

extern Test test;