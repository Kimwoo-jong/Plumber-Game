#pragma once
#include "Include.h"


Test test;



Test::Test(void)
{
	t_W = 600;
	t_H = 300;
}

Test::~Test(void)
{
}

void Test::Init()
{

	char FileName[256];

	for(int i = 0; i<20; i++ )
	{
		sprintf_s(FileName, "./resource/Img/Test/%04d.png", i+1);
		testimg[i].Create(FileName,false,D3DCOLOR_XRGB(0,0,0));
	}

}





void Test::Update()
{

	if (GetTickCount() - testani1 > 100)
	{
		testcount++;
		if (testcount>19) testcount = 0;
		testani1 = GetTickCount();
	}
	
}





void Test::Draw()
{
	if (Gmanager.m_GameStart == true)
		testimg[testcount].Render(t_W, t_H, 0, 1, 1);


}

