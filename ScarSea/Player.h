#pragma once
class Player : public Object
{
private:
	int m_MagicPoint;
	int m_Time;
	float m_SlowTime;

	bool m_SlowMagicActive;

	Sprite* m_SlowMagicRange;

	Sprite* m_SlowMagicUI;
	Sprite* m_BombMagicUI;
	Sprite* m_TimeMagicUI;

public:
	CANNONTYPE m_InstallCannonType;
	bool m_Install;
	Gold * m_Gold;	//ÇÃ·¹ÀÌ¾î µ·

	int m_iKillCount;

public:
	Player();
	~Player();

	void Update(float deltaTime);
	void Render();
};