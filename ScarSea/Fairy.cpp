#include "stdafx.h"
#include "Fairy.h"


Fairy::Fairy(MAPPOINT* point) : Enemy(point)
{
	m_Sp = Sprite::Create(L"Painting/DeepFlow.png");
	m_Sp->SetParent(this);
	m_Hp = 2;

	m_HpBar->SetPosition(0, -40);
	m_HpRect->SetPosition(0, -40);
	m_Minus = 1;
}

Fairy::~Fairy()
{
}

void Fairy::OnCollision(Object * other)
{
	if (m_Hp != 1)
		m_Minus += 1;

	m_Hp -= 1;
	m_HpBar->SetRectSize(m_Minus, 1.f);
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
