#include "stdafx.h"
#include "Player.h"


Player::Player()
	: m_Install(0)
	, m_InstallCannonType(CANNONTYPE::NONE)
	, m_MagicPoint(0)
	, m_Time(0)
	, m_iKillCount(0)
	, m_SlowTime(0)
{
	m_Gold = new Gold();
	m_Gold->SetPosition(50, 100);

	ObjMgr->KeepObject(m_Gold);
	m_Gold->m_Layer = 3;

	m_SlowMagicRange = Sprite::Create(L"Painting/MagicRange.png");
	m_SlowMagicRange->SetScale(0.2f, 0.2f);
	m_SlowMagicRange->m_Visible = false;
}

Player::~Player()
{
}

float ff = 0.f;

void Player::Update(float deltaTime)
{
	if(false == m_SlowMagicActive)
		m_SlowMagicRange->SetPosition(INPUT->GetMousePos().x, INPUT->GetMousePos().y);

	ff += deltaTime;

	system("cls");
	printf("DElTA TIME : %f\n", ff);

	m_Time += deltaTime;
	if (m_Time > 0.5)
	{
		m_MagicPoint += 1;
		if (m_MagicPoint > 3)
			m_MagicPoint = 3;
	}

	//오른쪽 클릭 -> 범위가 보이고 
	//범위가 visible = 1 인 상태에서 왼족 클릭하면 스프라이트가 마우스를 따라가지고 않고 그 자리에 멈춘다.
	//몇 초 후에 스프라이트를 삭제한다.

	//오른쪽 클릭 하면
	if (m_SlowMagicActive == false)
	{
		if (INPUT->GetKey(VK_RBUTTON) == KeyState::UP)
		{
			m_SlowMagicRange->m_Visible = true;
		}
	}

	if (INPUT->GetKey(VK_LBUTTON) == KeyState::UP && m_SlowMagicRange->m_Visible == true)
	{
		m_SlowMagicActive = true;

	}

	if (m_SlowMagicActive)
	{
		m_SlowTime += deltaTime;

		if (m_SlowTime > 10.f)
		{
			m_SlowMagicActive = false;
			m_SlowMagicRange->m_Visible = false;
			m_SlowTime = 0.f;
		}

		auto iter = ObjMgr->m_Enemys.begin();
		auto iterEnd = ObjMgr->m_Enemys.end();

		for (; iter != iterEnd; ++iter)
		{
			//마법진과 적 사이 거리를 
			float leng = D3DXVec2Length(&(m_SlowMagicRange->m_Position - (*iter)->m_Position));
			if (leng < 200.f)
			{
				((Enemy*)(*iter))->m_Slow = 0.2f;
			}
			else
			{
				((Enemy*)(*iter))->m_Slow = 1.f;
			}
		}
	}
}

void Player::Render()
{
	m_SlowMagicRange->Render();
}