#pragma once

enum class CANNONTYPE
{
	CLAM,
	CORAL,
	ANEMONE,
	NONE
};

class Cannon : public Object
{
	//업그레이드 기능 있어야함
protected:
	CANNONTYPE m_Type;
	int m_UpgradeLevel;
	float m_AttackRange;

	float m_Delay;
	float m_Time;

	Vec2 m_Dir;

public:
	Cannon(Vec2 Pos);
	~Cannon();

	void Update(float deltaTime);
	void Render();
};