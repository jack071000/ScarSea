#include "stdafx.h"
#include "Suburb.h"
#include"EnemysHeader.h"
#include"DudeHeader.h"
#include"CannonSpot.h"

Suburb::Suburb()
{
	m_BackGround = Sprite::Create(L"Painting/Map.png");
	m_BackGround->Translate(960, 540);

	SetMapPoint();
	auto enemy = new Fairy(mapPoint);
	ObjMgr->KeepObject(enemy);

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
struct FISHCANNONPOINT
{
	Sprite* m_PlusButton;
	bool m_Intalled;
	Cannon* m_Cannon;
	D3DXVECTOR2 Pos;
};

void Suburb::SetFishCannonPoint()
{
}


void Suburb::Update(float deltaTime)
{
}

void Suburb::Render()
{
	m_BackGround->Render();
}