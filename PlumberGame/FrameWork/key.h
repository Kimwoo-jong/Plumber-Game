#pragma once
#include "Include.h"

class Key
{
public:
	Key(void);
	~Key(void);
	
	//동시 키 선택을 위한 변수
	DWORD KeyTime;
	DWORD KeyTime1;
	DWORD KeyTime2;
	DWORD KeyTime3;
	
	void Update();
};

extern Key key;