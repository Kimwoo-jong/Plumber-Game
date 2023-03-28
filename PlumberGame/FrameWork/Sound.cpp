#include "Include.h"

Sound sound;

Sound::Sound(void)
{
}

Sound::~Sound(void)
{
}

void Sound::Init()
{
	//사운드 적용
	g_pSoundManager->Create(&m_Water, (LPWSTR)L"./resource/Sound/WaterSound.wav", 0, GUID_NULL);
	g_pSoundManager->Create(&m_Menu, (LPWSTR)L"./resource/Sound/Menusound.wav", 0, GUID_NULL);
	g_pSoundManager->Create(&m_Intro, (LPWSTR)L"./resource/Sound/Introsound.wav", 0, GUID_NULL);
	g_pSoundManager->Create(&m_Play, (LPWSTR)L"./resource/Sound/Playsound.wav", 0, GUID_NULL);
	g_pSoundManager->Create(&m_PipePick, (LPWSTR)L"./resource/Sound/Picksound.wav", 0, GUID_NULL);
	g_pSoundManager->Create(&m_PipeSet, (LPWSTR)L"./resource/Sound/Setsound.wav", 0, GUID_NULL);
	g_pSoundManager->Create(&m_PipeWlong, (LPWSTR)L"./resource/Sound/Wlongsound.wav", 0, GUID_NULL);
	g_pSoundManager->Create(&m_PipeRotate, (LPWSTR)L"./resource/Sound/Rotatesound.wav", 0, GUID_NULL);
	g_pSoundManager->Create(&m_Menuon, (LPWSTR)L"./resource/Sound/Menuonsound.wav", 0, GUID_NULL);
	g_pSoundManager->Create(&m_Menuoff, (LPWSTR)L"./resource/Sound/Menuoffsound.wav", 0, GUID_NULL);
	g_pSoundManager->Create(&m_Menusel, (LPWSTR)L"./resource/Sound/Menuselectsound.wav", 0, GUID_NULL);
	g_pSoundManager->Create(&m_Valve, (LPWSTR)L"./resource/Sound/Valvesound.wav", 0, GUID_NULL);
	g_pSoundManager->Create(&m_Clear, (LPWSTR)L"./resource/Sound/Clearsound.wav", 0, GUID_NULL);
	g_pSoundManager->Create(&m_Over, (LPWSTR)L"./resource/Sound/Oversound.wav", 0, GUID_NULL);
	g_pSoundManager->Create(&m_Alert, (LPWSTR)L"./resource/Sound/Alertsound.wav", 0, GUID_NULL);
	g_pSoundManager->Create(&m_Clock, (LPWSTR)L"./resource/Sound/Clocksound.wav", 0, GUID_NULL);
}