#pragma once
class Fairy : public Enemy
{

public:
	Fairy(MAPPOINT* point);
	~Fairy();

	void OnCollision(Object* other);
	void Update(float deltaTime);
	void Render();
};