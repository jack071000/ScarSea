#include "stdafx.h"
#include "Player.h"


Player::Player()
	: m_Install(0)
	, m_InstallCannonType(CANNONTYPE::NONE)
	, m_MagicPoint(0)
	, m_Time(0)
	, m_iKillCount(0)
{
	m_Gold = new Gold();
	m_Gold->SetPosition(50, 100);
	ObjMgr->KeepObject(m_Gold);
	m_Gold->m_Layer = 3;
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	m_Time += deltaTime;
	if (m_Time > 0.5)
	{
		m_MagicPoint += 1;
		if (m_MagicPoint > 3)
			m_MagicPoint = 3;
	}
}

void Player::Render()
{
}