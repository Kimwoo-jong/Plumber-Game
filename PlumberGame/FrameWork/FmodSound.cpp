#include "FMODENGIN/inc/fmod.hpp"
#pragma comment (lib, "FMODENGIN/lib/fmodex64_vc.lib")
using namespace FMOD;

#include "FmodSound.h"
#include<map>

class FmodSound
{
	System *m_pSystem;
	int m_Index;
	Channel *m_pBGChannel;
	float m_volume;
public:
	std::map<std::string, int> m_CheckList;
	std::map<int, Sound*> m_SoundList;

	FmodSound()
	{
		System_Create(&m_pSystem);
		m_pSystem->init(10, FMOD_INIT_NORMAL, 0);
		m_Index = 0;
		m_volume = 1.0f; // 1.0f가 볼륨 최고
		m_pBGChannel = nullptr;
	}
	~FmodSound()
	{
		m_CheckList.clear();
		for (auto & Iter : m_SoundList)
		{
			Iter.second->release();
		}
		m_SoundList.clear();
		m_pSystem->release();
		m_pSystem->close();
	}

	int AddSoundFile(std::string _FullPath, bool _IsLoop)
	{
		auto Find = m_CheckList.find(_FullPath);
		if (Find != m_CheckList.end())
		{
			return Find->second;
		}
		Sound *pSound = nullptr;
		int Mode = FMOD_HARDWARE | (_IsLoop ? FMOD_LOOP_NORMAL | FMOD_DEFAULT : FMOD_LOOP_OFF);
		m_pSystem->createSound(_FullPath.c_str(), Mode, 0, &pSound);
		if (pSound == nullptr)
		{
			return -1;
		}
		m_CheckList.insert(std::make_pair(_FullPath, m_Index));
		m_SoundList.insert(std::make_pair(m_Index, pSound));

		return m_Index++;
	}

	void EffectPlay(int _SoundNum)
	{
		auto Find = m_SoundList.find(_SoundNum);
		Channel *pChannel = nullptr;
		m_pSystem->playSound(FMOD_CHANNEL_FREE, Find->second, 0, &pChannel);
	}
	void BGPlay(int _SoundNum)
	{
		auto Find = m_SoundList.find(_SoundNum);

		m_pSystem->playSound(FMOD_CHANNEL_REUSE, Find->second, 0, &m_pBGChannel);
	}

	void BGStop()
	{
		if (m_pBGChannel != nullptr)
		{
			m_pBGChannel->stop();
		}
	}

	void VolumDown()
	{
		m_volume -= 0.1f;
		if (m_volume <= 0) m_volume = 0;
		m_pBGChannel->setVolume(m_volume);
	}

	void VolumUp()
	{
		m_volume += 0.1f;
		if (m_volume >= 1.0) m_volume = 1.0;
		m_pBGChannel->setVolume(m_volume);
	}
};

static FmodSound g_SoundMgr; // 전역변수

int	AddSoundFile(std::string _FullPath, bool _IsLoop)
{
	return g_SoundMgr.AddSoundFile(_FullPath, _IsLoop);
}

void EffectPlay(int _SoundNum)
{
	g_SoundMgr.EffectPlay(_SoundNum);
}

void BGPlay(int _SoundNum)
{
	g_SoundMgr.BGPlay(_SoundNum);
}

void VolumUp()
{
	g_SoundMgr.VolumUp();
}

void VolumDown()
{
	g_SoundMgr.VolumDown();
}

void BGStop()
{
	g_SoundMgr.BGStop();
}