#include "stdafx.h"
#include "Cannon.h"
#include"Bullet.h"

Cannon::Cannon(Vec2 Pos)
	: m_Type(CANNONTYPE::NONE)
	, m_AttackRange(300.f)
	, m_Delay(0.5)
	, m_Time(0)
	, m_UpgradeLevel(0)
	, m_UpgradeButtonOn(0)
{
	m_Position = Pos;

	m_UpgradeButton = Sprite::Create(L"Painting/Upgrade1.png");
	m_UpgradeButton->m_Visible = false;
	m_UpgradeButton->SetPosition(m_Position.x , m_Position.y - 100);
}

Cannon::~Cannon()
{
}

void Cannon::Attack()
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

void Cannon::Update(float deltaTime)
{
	m_Time += deltaTime;

	if (m_Time > m_Delay)
		Attack();

	//ĳ���� ������ ��

	if(m_UpgradeButtonOn == false)
	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_CannonSp->m_Collision))
	{
		if (INPUT->GetButtonDown())
		{
			switch (m_UpgradeLevel)
			{
			case 0:
				m_UpgradeButton->Init(L"Painting/Upgrade1.png");
				break;

			case 1:
				m_UpgradeButton->Init(L"Painting/Upgrade2.png");
				break;

			case 2:
				m_UpgradeButton->Init(L"Painting/Upgrade3.png");
				break;
			}

			m_UpgradeButton->m_Visible = true;
			m_UpgradeButtonOn = true;
			INPUT->ButtonDown(false);
		}
	}

	//ĳ���� ���� ���׷��̵� ��ư�� ������ ��
	if(m_UpgradeButtonOn == true)
	{
		if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_UpgradeButton->m_Collision))
		{
			if (INPUT->GetButtonDown())
			{
				switch (m_UpgradeLevel)
				{
				case 0:
					if (PMgr->m_Gold->GetGold() > 200)
					{
						PMgr->m_Gold->MinusGold(200);
					}
					else
						return;
					break;

				case 1:
					if (PMgr->m_Gold->GetGold() > 300)
					{
						PMgr->m_Gold->MinusGold(300);
					}
					else
						return;
					break;
					
				case 2:
					if (PMgr->m_Gold->GetGold() > 400)
					{
						PMgr->m_Gold->MinusGold(400);
					}
					else
						return;

					break;
				}
				
				//�ڽ��� ������ ���� ������ �ɷ�ġ�� �޶�� ��.
				m_UpgradeButton->m_Visible = false;
				m_UpgradeLevel++;
				m_UpgradeButtonOn = false;
			}
		}

		else
		{
			if (INPUT->GetButtonDown())
			{
				if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_CannonSp->m_Collision) == false)
				{
					m_UpgradeButton->m_Visible = false;
					m_UpgradeButtonOn = false;
				}
			}
		}
	}
}

void Cannon::Render()
{
	m_UpgradeButton->Render();
}