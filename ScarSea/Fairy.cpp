#include "stdafx.h"
#include "Fairy.h"


Fairy::Fairy(MAPPOINT* point) : Enemy(point)
{
	m_Sp = Sprite::Create(L"Painting/DeepFlow.png");
	m_Sp->SetParent(this);
	m_Hp = 4;

	m_HpBar->SetPosition(0, -40);
	m_HpRect->SetPosition(0, -40);
	m_MaxHp = 4.f;
}

Fairy::~Fairy()
{
}

void Fairy::OnCollision(Object * other)
{
	m_Hp -= 1;

	if(m_Hp != 0)
		m_HpBar->SetRectSize(m_MaxHp / m_Hp, 1);
}

void Fairy::Update(float deltaTime)
{
	Enemy::Update(deltaTime);
	
}

void Fairy::Render()
{
	Enemy::Render();
	m_Sp->Render();
}
