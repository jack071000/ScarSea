#pragma once

struct MAPPOINT
{
	D3DXVECTOR2 Pos;
	int Type;
};


class Enemy : public Object
{
protected:
	MAPPOINT * m_Road;
	Sprite* m_HpBar;
	Sprite* m_HpRect;

	Sprite* m_Sp;

	Vec2 m_Dir;

	float m_Speed;
	float m_Time;
	float m_CoE;

	bool m_IsArrived;
	int m_Order;
	float m_Hp;
	float m_MaxHp;

public:
	float m_Slow;

public:
	Enemy(MAPPOINT* point);
	~Enemy();

	void Attack();

	void Update(float deltaTime);
	void Render();
};