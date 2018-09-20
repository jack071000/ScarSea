#pragma once
class Octopus : public Enemy
{
public:
	Octopus(MAPPOINT* point);
	~Octopus();

	void OnCollision(Object* other);
	void Update(float deltaTime);
	void Render();
};

