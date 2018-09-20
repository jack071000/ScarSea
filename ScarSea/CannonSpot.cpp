#include "stdafx.h"
#include "CannonSpot.h"


CannonSpot::CannonSpot()
	: m_Cannon(NULL)
	, m_ButtonActive(0)
	, m_Intalled(false)
{
	m_PlusButton = Sprite::Create(L"Painting/Plus.png");
}


CannonSpot::~CannonSpot()
{
}

void CannonSpot::Update(float deltaTime)
{
	if (m_Intalled)
	{
		m_ButtonActive = false;
	}

	if (GetButtonActive() == false)
		m_PlusButton->m_Visible = false;
	else
	{
		m_PlusButton->m_Visible = true;

		if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_PlusButton->m_Collision))
		{
			if (INPUT->GetButtonDown() == true)
			{
				//설치
				//오브젝트 매니져에 캐논 추가
			}
		}
	}

}

void CannonSpot::Render()
{
	m_PlusButton->Render();
}
