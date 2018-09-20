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

	bool m_IsArrived;
	int m_Order;
	int m_Hp;

public:
	Enemy(MAPPOINT* point);
	~Enemy();

	void Attack();

	void Update(float deltaTime);
	void Render();
};