#pragma once
#include "Include.h"

class Key
{
public:
	Key(void);
	~Key(void);
	
	//���� Ű ������ ���� ����
	DWORD KeyTime;
	DWORD KeyTime1;
	DWORD KeyTime2;
	DWORD KeyTime3;
	
	void Update();
};

extern Key key;