#include "stdafx.h"
#include "SceneDirector.h"


SceneDirector::SceneDirector()
{
}


SceneDirector::~SceneDirector()
{
}

void SceneDirector::ChangeScene(Object * newScene)
{
	if (m_CurrentScene)
	{
		SAFE_DELETE(m_CurrentScene);
	}

	m_CurrentScene = newScene;
}

void SceneDirector::Update(float deltaTime)
{
	Input::GetInst()->Update();
	ObjMgr->Update(deltaTime);
	if (m_CurrentScene)
		m_CurrentScene->Update(deltaTime);
	
}

void SceneDirector::Render()
{
	if (m_CurrentScene)
		m_CurrentScene->Render();

	ObjMgr->Render();
}
