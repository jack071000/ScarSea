#include "stdafx.h"
#include "Clam.h"


Clam::Clam(Vec2 Pos) : Cannon(Pos)
{
	m_CannonSp= Sprite::Create(L"Painting/Run.png");
	m_CannonSp->SetParent(this);
	m_Delay = 2.f;
	m_Name = L"Clam";
}

Clam::~Clam()
{
}

void Clam::Attack(Vec2 dir, Vec2 Pos)
{
	Bullet* bullet = new Bullet(dir, m_Position, L"Painting/Bullet.png");
	ObjMgr->KeepObject(bullet);
}

void Clam::Update(float deltaTime)
{
	Cannon::Update(deltaTime);

	if (m_Dir != Vec2(0.f,0.f))
	{
		Attack(m_Dir, m_Position);
		m_Dir = Vec2(0.f, 0.f);
	}
}

void Clam::Render()
{
	Cannon::Render();

	m_CannonSp->Render();
}
