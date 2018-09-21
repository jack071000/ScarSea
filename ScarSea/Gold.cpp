#include "stdafx.h"
#include "Gold.h"


Gold::Gold()
	: m_iHGold(0)
	, m_iOGold(0)
	, m_iTGold(0)
	, m_iTHGold(0)
	, m_iTotalGold(0)
{
	m_GoldUI = Sprite::Create(L"Painting/Gold.png");
	m_GoldUI->SetParent(this);

	m_THGold = new Font();
	m_HGold = new Font();
	m_TGold = new Font();
	m_OGold = new Font();

	m_THGold->SetParent(this);
	m_HGold->SetParent(this);
	m_TGold->SetParent(this);
	m_OGold->SetParent(this);
		   
	//37   
	m_GoldUI->SetPosition(75, -70);
	m_THGold->SetPosition(-20, 0);
	m_HGold->SetPosition(40, 0);
	m_TGold->SetPosition(100, 0);
	m_OGold->SetPosition(160, 0);

	m_THGold->m_Layer = 2;
	m_HGold->m_Layer = 2;
	m_TGold->m_Layer = 2;
	m_OGold->m_Layer = 2;
}

Gold::~Gold()
{
}

void Gold::Calc()
{
	m_iTHGold = m_iTotalGold / 1000;
	m_iHGold = (m_iTotalGold % 1000) / 100;
	m_iTGold = (m_iTotalGold % 100) / 10;
	m_iOGold = m_iTotalGold % 10;
}

void Gold::Update(float deltaTime)
{
	Calc();

	m_THGold->SetFrame(m_iTHGold);
	m_HGold->SetFrame(m_iHGold);
	m_TGold->SetFrame(m_iTGold);
	m_OGold->SetFrame(m_iOGold);

	m_THGold->Update(deltaTime);
	m_HGold->Update(deltaTime);
	m_TGold->Update(deltaTime);
	m_OGold->Update(deltaTime);
}

void Gold::Render()
{
	m_GoldUI->Render();
	m_THGold->Render();
	m_HGold->Render();
	m_TGold->Render();
	m_OGold->Render();
}
