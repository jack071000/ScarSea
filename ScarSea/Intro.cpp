#include "stdafx.h"
#include "Intro.h"
#include"Suburb.h"

Intro::Intro()
{
	m_AIntro = new Animation();
	m_AIntro->Init(60, 1);
	m_AIntro->AddContinueFrame(L"Painting/", 1, 3);
	m_AIntro->SetPosition(960, 540);

	ObjMgr->KeepObject(m_AIntro);
}

Intro::~Intro()
{
}

void Intro::Update(float deltaTime)
{
	if (INPUT->GetKey(VK_SPACE) == KeyState::PRESS)
	{
		ObjMgr->Release();
		SceneDirector::GetInst()->ChangeScene(new Suburb());
	}
}

void Intro::Render()
{
}
