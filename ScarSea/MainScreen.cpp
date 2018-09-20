#include "stdafx.h"
#include "MainScreen.h"
#include"Intro.h"

MainScreen::MainScreen()
{
	m_BackGround = Sprite::Create(L"Painting/BackGround.png");
	m_BackGround->Translate(1920 / 2, 1080 / 2);
}


MainScreen::~MainScreen()
{
}

void MainScreen::Update(float deltaTime)
{
	if (INPUT->GetKey('1') == KeyState::PRESS)
		m_BackGround->Translate(5.f, 0.f);

	if (INPUT->GetKey(VK_SPACE) == KeyState::PRESS)
		SceneDirector::GetInst()->ChangeScene(new Intro());
}

void MainScreen::Render()
{
	m_BackGround->Render();
}
