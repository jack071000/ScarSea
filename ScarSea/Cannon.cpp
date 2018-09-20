#include "stdafx.h"
#include "Cannon.h"
#include"Bullet.h"

Cannon::Cannon(Vec2 Pos)
	: m_Type(CANNONTYPE::NONE)
	, m_AttackRange(300.f)
	, m_Delay(0.5)
	, m_Time(0)
	, m_UpgradeLevel(0)
{
	m_Position = Pos;
}


Cannon::~Cannon()
{
}

void Cannon::Update(float deltaTime)
{
	m_Time += deltaTime;

	if (m_Time > m_Delay)
	{
		D3DXVECTOR2 pos = { 0.f,0.f };

		auto EnemyList = ObjMgr->m_Enemys;
		auto iter = EnemyList.begin();

		for (; iter != EnemyList.end(); ++iter)
		{
			if (m_AttackRange > D3DXVec2Length(&((*iter)->m_Position - m_Position)))
			{
				pos = (*iter)->m_Position;
				break;
			}
		}

		if (pos != D3DXVECTOR2(0.f, 0.f))
		{
			D3DXVECTOR2 dir;
			D3DXVec2Normalize(&dir, &(pos - m_Position));
			m_Dir = dir;
		}

		m_Time = 0;
	}
}

void Cannon::Render()
{
}
