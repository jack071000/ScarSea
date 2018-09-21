#pragma once
class Gold : public Object
{
	Font* m_THGold;
	Font* m_HGold;
	Font* m_TGold;
	Font* m_OGold;

	Sprite* m_GoldUI;

	int m_iTHGold;
	int m_iHGold;
	int m_iTGold;
	int m_iOGold;

	int m_iTotalGold;

public:
	Gold();
	~Gold();

	void PlusGold(int gold) { m_iTotalGold += gold; }
	void MinusGold(int gold) { m_iTotalGold -= gold; }
	int GetGold() { return m_iTotalGold; }

	void Calc();

	void Update(float deltaTime);
	void Render();
};