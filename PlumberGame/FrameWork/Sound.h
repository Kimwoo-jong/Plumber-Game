#pragma once

class Sound
{
public:
	Sound(void);
	~Sound(void);

CSoundManager* g_pSoundManager;

//사운드용
CSound*	m_Water;
CSound*	m_Menu;
CSound*	m_Intro;
CSound*	m_Play;
CSound*	m_PipePick;
CSound*	m_PipeSet;
CSound*	m_PipeWlong;
CSound*	m_PipeRotate;
CSound*	m_Menuon;
CSound*	m_Menuoff;
CSound*	m_Menusel;
CSound*	m_Valve;
CSound*	m_Clear;
CSound*	m_Over;
CSound*	m_Alert;
CSound*	m_Clock;

void Init();	
};

extern Sound sound;