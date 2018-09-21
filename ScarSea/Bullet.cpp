#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet(Vec2 Dir, Vec2 Pos , std::wstring fileName)
{
	m_Speed = 200.f;
	m_Dir = Dir;
	m_Position = Pos;
	m_Bullet = Sprite::Create(fileName);
	m_Bullet->SetParent(this);
	ObjMgr->m_Bullets.push_back(this);
}

Bullet::~Bullet()
{
}

void Bullet::OnCollision(Object * other)
{
	ObjMgr->RemoveObject(this);
}

void Bullet::Update(float deltaTime)
{
	Translate(m_Dir.x * m_Speed * deltaTime, m_Dir.y *m_Speed * deltaTime);
	if (App::GetInst()->IsInWindowRect(m_Position.x, m_Position.y) == false)
	{
		ObjMgr->RemoveObject(this);
	}
}

void Bullet::Render()
{
	m_Bullet->Render();
}
