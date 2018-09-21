#include "stdafx.h"
#include "Suburb.h"
#include"EnemysHeader.h"
#include"DudeHeader.h"
#include"CannonSpot.h"

Suburb::Suburb()
{
	m_BackGround = Sprite::Create(L"Painting/Map.png");
	m_BackGround->Translate(960, 540);

	ObjMgr->KeepObject(m_BackGround);
	m_BackGround->m_Layer = -1;

	SetMapPoint();
	ObjMgr->KeepObject(PlayerMgr::GetInst()->GetPlayer());
	SetFishCannonPoint();
}

Suburb::~Suburb()
{
}

void Suburb::SetMapPoint()
{
	mapPoint[0] = { Vec2(1915, 680) , 0 };
	mapPoint[1] = { Vec2(1040, 108) , 0 };
	mapPoint[2] = { Vec2(700 , 100) , 1 };
	mapPoint[3] = { Vec2(750 , 300) , 1 };
	mapPoint[4] = { Vec2(1300, 735) , 0 };
	mapPoint[5] = { Vec2(1300, 850) , 1 };
	mapPoint[6] = { Vec2(1050, 920) , 1 };
	mapPoint[7] = { Vec2(530 , 590) , 0 };
	mapPoint[8] = { Vec2(475 , 560) , 1 };
	mapPoint[9] = { Vec2(410 , 595) , 1 };
	mapPoint[10] = { Vec2(0  , 900) , 2 };
}

void Suburb::SetFishCannonPoint()
{
	mapCannonSpot[0].Init(1657, 388);
	mapCannonSpot[1].Init(1416, 225);
	mapCannonSpot[2].Init(1490, 580);
	mapCannonSpot[3].Init(1210, 427);
	mapCannonSpot[4].Init(975, 275);
	mapCannonSpot[5].Init(1085, 755);
	mapCannonSpot[6].Init(840, 590);
	mapCannonSpot[7].Init(740, 905);
	mapCannonSpot[8].Init(477, 740);
	mapCannonSpot[9].Init(120, 630);

	for (int i = 0; i < 10; i++)
	{
		ObjMgr->KeepObject(&mapCannonSpot[i]);
	}
}


void Suburb::Update(float deltaTime)
{
	m_Time += deltaTime;
	if (m_Time > 3)
	{
		auto enemy = new Fairy(mapPoint);
		ObjMgr->KeepObject(enemy);

		m_Time = 0;
	}

	if (PMgr->m_Install)
	{
		for (int i = 0; i < 10; i++)
		{
			mapCannonSpot[i].ActivateButton();
		}
	}

	if (PMgr->m_Install == false)
	{
		for (int i = 0; i < 10; i++)
		{
			mapCannonSpot[i].DisableButton();
		}
	}
}

void Suburb::Render()
{
	 
}