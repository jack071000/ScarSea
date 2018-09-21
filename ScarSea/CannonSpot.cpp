#include "stdafx.h"
#include "CannonSpot.h"
#include"DudeHeader.h"

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

void CannonSpot::Init(float x, float y)
{
	m_Position = Vec2(x,y);
	m_PlusButton->SetPosition(x,y);
}

void CannonSpot::Update(float deltaTime)
{
	if (m_Intalled)
	{
		m_ButtonActive = false;
	}

	if (m_ButtonActive == false)
		m_PlusButton->m_Visible = false;

	

	//버튼이 나와있는데 다른 곳을 눌렀을 때

	//상점에서 버튼을 눌렀을 때
	if(m_ButtonActive == true)
	{
		m_PlusButton->m_Visible = true;
		
		if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_PlusButton->m_Collision))
		{
			if (INPUT->GetButtonDown() == true)
			{
				//설치
				switch (PlayerMgr::GetInst()->GetPlayer()->m_InstallCannonType)
				{
				case CANNONTYPE::CLAM:
					m_Cannon = new Clam(Vec2(m_Position.x, m_Position.y));
					break;

				case CANNONTYPE::CORAL:
					m_Cannon = new Coral(Vec2(m_Position.x, m_Position.y));
					break;

				case CANNONTYPE::ANEMONE:
					m_Cannon = new Anemone(Vec2(m_Position.x, m_Position.y));
					break;
				}

				//오브젝트 매니져에 캐논 추가

				INPUT->ButtonDown(false);
				ObjMgr->KeepObject(m_Cannon);
				m_Intalled = true;

				PMgr->m_Install = false;
				PMgr->m_InstallCannonType = CANNONTYPE::NONE;
			}
		}
	}
}

void CannonSpot::Render()
{
	m_PlusButton->Render();
}