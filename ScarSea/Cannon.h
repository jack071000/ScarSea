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
	//���׷��̵� ��� �־����
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