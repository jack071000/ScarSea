#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(MAPPOINT* point)
	: m_Hp(0)
	, m_IsArrived(0)
	, m_Order(1)
	, m_Speed(30)
	, m_Time(0)
{
	m_Road = point;

	m_HpBar = Sprite::Create(L"Painting/Hp_Bar.png");
	m_HpBar->SetParent(this);
	m_HpRect = Sprite::Create(L"Painting/Hp_Rect.png");
	m_HpRect->SetParent(this);
	
	m_Position = m_Road[0].Pos;
	D3DXVec2Normalize(&m_Dir, &(m_Road[1].Pos - m_Road[0].Pos));
	ObjMgr->m_Enemys.push_back(this);
}

Enemy::~Enemy()
{
}

void Enemy::Attack()
{
}

void Enemy::Update(float deltaTime)
{
	if (m_Hp <= 0)
	{
		ObjMgr->RemoveObject(this);
		PlayerMgr::GetInst()->GetPlayer()->m_Gold->PlusGold(10);
	}

	if (5.f < D3DXVec2Length(&(m_Road[m_Order].Pos - m_Position)))
	{
		//3ÀÌ µµÂø°î¼±
		//2°¡ µµÂøÁ÷¼±

		if (m_Road[m_Order].Type == 1 || m_Road[m_Order].Type == 3)
		{
			m_Time += deltaTime * 0.1f;

			m_Position = pow((1 - m_Time), 2) * m_Road[m_Order - 2].Pos + 2 * m_Time * (1 - m_Time) * m_Road[m_Order - 1].Pos
				+ m_Time * m_Time * m_Road[m_Order].Pos;
		}
		else
			Translate(m_Dir.x * m_Speed * deltaTime, m_Dir.y * m_Speed * deltaTime);
	}
	else
	{
		if (2 == m_Road[m_Order].Type || 3 == m_Road[m_Order].Type)
			m_IsArrived = true;
		else if (1 == m_Road[m_Order + 1].Type)
			m_Order += 2;
		else
		{
			++m_Order;
			D3DXVec2Normalize(&m_Dir, &(m_Road[m_Order].Pos - m_Road[m_Order - 1].Pos));
		}

		m_Time = 0.f;
	}
}

void Enemy::Render()
{
	m_HpBar->Render();
	m_HpRect->Render();
}
