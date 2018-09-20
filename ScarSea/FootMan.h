#pragma once
class FootMan : public Enemy
{
public:
	FootMan(MAPPOINT* point);
	~FootMan();

	void OnCollision(Object* other);
	void Update(float deltaTime);
	void Render();
};