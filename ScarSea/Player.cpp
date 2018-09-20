#include "stdafx.h"
#include "Player.h"


Player::Player()
	: m_Install(0)
	, m_InstallCannonType(CANNONTYPE::NONE)
	, m_MagicPoint(0)
	, m_Time(0)
{
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
