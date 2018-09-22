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
	Sprite * m_CannonSp;
	Object* m_Target;
	CANNONTYPE m_Type;
	int m_UpgradeLevel;

	Sprite* m_UpgradeButton;

	//업그레이드 시 늘어나는 것들
	float m_Delay;
	float m_AttackRange;
	float m_Time;

	Vec2 m_Dir;

	bool m_UpgradeButtonOn;

public:
	Cannon(Vec2 Pos);
	~Cannon();

	void Attack();
	void Update(float deltaTime);
	void Render();
};