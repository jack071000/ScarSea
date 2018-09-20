#pragma once
class Bullet: public Object
{
	Vec2 m_Dir;
	Sprite* m_Bullet;
	float m_Speed;

public:
	Bullet(Vec2 Dir, Vec2 Pos, std::wstring fileName);
	~Bullet();

	void OnCollision(Object * other);
	void Update(float deltaTime);
	void Render();
};