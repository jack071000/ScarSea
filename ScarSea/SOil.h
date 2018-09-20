#pragma once
class SOil : public Enemy
{
public:
	SOil(MAPPOINT* point);
	~SOil();

	void OnCollision(Object* other);
	void Update(float deltaTime);
	void Render();
};