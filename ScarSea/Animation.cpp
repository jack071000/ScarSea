#include "stdafx.h"
#include "Animation.h"


Animation::Animation()
	: m_AutoPlay(0)
	, m_CurrentFrame(0)
	, m_Delay(0)
	, m_FrameCount(0)
{
}

Animation::~Animation()
{
}

void Animation::AddFrame(std::wstring fileName)
{
	auto sprite = Sprite::Create(fileName);
	sprite->SetParent(this);
	m_Anim.push_back(sprite);
}

void Animation::AddContinueFrame(std::wstring fileName, int firstFrame, int lastFrame)
{
	if (firstFrame > lastFrame)
	{
		for (int i = firstFrame; i >= lastFrame; i--)
		{
			auto sprite = Sprite::Create(fileName.c_str() + std::to_wstring(i) + L".png");

			sprite->SetParent(this);
			if (sprite)
				m_Anim.push_back(sprite);
		}
	}
	else
	{
		for (int i = firstFrame; i <= lastFrame; i++)
		{
			auto sprite = Sprite::Create(fileName.c_str() + std::to_wstring(i) + L".png");

			sprite->SetParent(this);
			if (sprite)
				m_Anim.push_back(sprite);
		}
	}

}
void Animation::Init(int delay, bool play)
{
	m_Delay = delay;
	m_AutoPlay = play;
}

void Animation::Update(float deltaTime)
{
	m_FrameCount++;

	if(m_AutoPlay == true)
		if (m_FrameCount > m_Delay)
		{
			m_CurrentFrame++;
			m_FrameCount = 0;
		}

	if (m_CurrentFrame > m_Anim.size() - 1)
	{
		m_CurrentFrame = 0;
	}
	
	m_Anim.at(m_CurrentFrame)->Update(deltaTime);
}

void Animation::Render()
{
	m_Anim.at(m_CurrentFrame)->Render();
}
