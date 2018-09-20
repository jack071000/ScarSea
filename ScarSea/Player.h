#pragma once
class Player : public Object
{
private:
	Gold * m_Gold;	//ÇÃ·¹ÀÌ¾î µ·
	int m_MagicPoint;
	int m_Time;

	Sprite* m_SlowMagicUI;
	Sprite* m_BombMagicUI;
	Sprite* m_TimeMagicUI;

	CANNONTYPE m_InstallCannonType;
	bool m_Install;

public:
	Player();
	~Player();

	void Update(float deltaTime);
	void Render();
};