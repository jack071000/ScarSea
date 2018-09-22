#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(MAPPOINT* point)
	: m_Hp(0.f)
	, m_IsArrived(0)
	, m_Order(1)
	, m_Speed(300.f)
	, m_Time(0.f)
	, m_CoE(0.f)
	, m_MaxHp(0.f)
	, m_Slow(1.f)
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
		PMgr->m_iKillCount++;
		ObjMgr->RemoveObject(this);
		PlayerMgr::GetInst()->GetPlayer()->m_Gold->PlusGold(10);
	}

	if (10.f < D3DXVec2Length(&(m_Road[m_Order].Pos - m_Position)))
	{
		//3ÀÌ µµÂø°î¼±
		//2°¡ µµÂøÁ÷¼±
		if (m_Road[m_Order].Type == 1 || m_Road[m_Order].Type == 3)
		{
			m_Time += deltaTime * m_CoE * m_Slow;

			m_Position = pow((1 - m_Time), 2) * m_Road[m_Order - 2].Pos + 2 * m_Time * (1 - m_Time) * m_Road[m_Order - 1].Pos
				+ m_Time * m_Time * m_Road[m_Order].Pos;
		}
		else
			Translate(m_Dir.x * m_Speed * deltaTime * m_Slow, m_Dir.y * m_Speed * deltaTime * m_Slow);
	}
	else
	{
		if (2 == m_Road[m_Order].Type || 3 == m_Road[m_Order].Type)
			m_IsArrived = true;
		else if (1 == m_Road[m_Order + 1].Type)
		{
			auto ren = D3DXVec2Length(&(m_Road[m_Order].Pos - m_Road[m_Order + 1].Pos));
			auto ren2 = D3DXVec2Length(&(m_Road[m_Order + 1].Pos - m_Road[m_Order + 2].Pos));
			ren += ren2;
			m_CoE = (m_Speed / ren) * 0.9f;

			m_Order += 2;
		}
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
