#include "stdafx.h"
#include "Shop.h"


Shop::Shop()
	: m_bPushedButton(false)
{
	m_PushButton = Sprite::Create(L"Painting/PushButton.png");
	m_PushButton->SetPosition(1870, 300);

	m_AnemoneImage = Sprite::Create(L"Painting/AnemoneImage.png");
	m_AnemoneImage->m_Visible = false;
	m_AnemoneImage->SetPosition(1700, 400);

	m_ClamImage = Sprite::Create(L"Painting/ClamImage.png");
	m_ClamImage->m_Visible = false;
	m_ClamImage->SetPosition(1700, 550);

	m_CoralImage = Sprite::Create(L"Painting/CoralImage.png");
	m_CoralImage->m_Visible = false;
	m_CoralImage->SetPosition(1700, 700);
}

Shop::~Shop()
{
}

void Shop::Update(float deltaTime)
{
	if (m_bPushedButton == false)
	{
		//버튼만 나와있게
		m_PushButton->m_Visible = true;

		m_AnemoneImage->m_Visible = false;
		m_ClamImage->m_Visible = false;
		m_CoralImage->m_Visible = false;
	}

	if(m_bPushedButton == true)
	{
		/*상점 항목들이 보이게*/
		m_PushButton->m_Visible = false;
		m_AnemoneImage->m_Visible = true;
		m_ClamImage->m_Visible = true;
		m_CoralImage->m_Visible = true;
	}

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_PushButton->m_Collision))
	{
		if (INPUT->GetButtonDown())
		{
			m_bPushedButton = true;

			m_PushButton->m_Visible = false;

			m_AnemoneImage->m_Visible = true;
			m_ClamImage->m_Visible = true;
			m_CoralImage->m_Visible = true;
		}
	}

	if (m_bPushedButton == false)
		return;

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_ClamImage->m_Collision))
	{
		//조개대포
		if (INPUT->GetButtonDown())
		{
			//플레이어에게 + 모양을 띄우라는 변수를 True 
			//플레이어가 설치
			PlayerMgr::GetInst()->GetPlayer()->m_Install = true;
			PlayerMgr::GetInst()->GetPlayer()->m_InstallCannonType = CANNONTYPE::CLAM;
		}
	}

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_CoralImage->m_Collision))
	{
		//산호 대포
		if (INPUT->GetButtonDown())
		{

		}
	}

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_AnemoneImage->m_Collision))
	{
		//말미잘 대포
		if (INPUT->GetButtonDown())
		{

		}
	}

}

void Shop::Render()
{
	m_PushButton->Render();

	m_ClamImage->Render();
	m_CoralImage->Render();
	m_AnemoneImage->Render();
}