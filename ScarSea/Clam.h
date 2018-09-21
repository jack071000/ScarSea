#pragma once
class Clam : public Cannon
{
public:
	Clam(Vec2 Pos);
	~Clam();

	void Attack(Vec2 dir, Vec2 Pos);
	void Update(float deltaTime);
	void Render();
};