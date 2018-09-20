#pragma once
class Fairy : public Enemy
{
	float m_Minus;

public:
	Fairy(MAPPOINT* point);
	~Fairy();

	void OnCollision(Object* other);
	void Update(float deltaTime);
	void Render();
};