#pragma once
class ShieldSoldier : public Enemy
{
public:
	ShieldSoldier(MAPPOINT* point);
	~ShieldSoldier();

	void OnCollision(Object* other);
	void Update(float deltaTime);
	void Render();
};

