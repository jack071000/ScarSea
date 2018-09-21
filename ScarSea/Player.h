#pragma once
class Player : public Object
{
private:
	int m_MagicPoint;
	int m_Time;

	Sprite* m_SlowMagicUI;
	Sprite* m_BombMagicUI;
	Sprite* m_TimeMagicUI;

public:
	CANNONTYPE m_InstallCannonType;
	bool m_Install;
	Gold * m_Gold;	//�÷��̾� ��

public:
	Player();
	~Player();

	void Update(float deltaTime);
	void Render();
};