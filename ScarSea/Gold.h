#pragma once
class Gold : public Object
{
	Font* m_HGold;
	Font* m_TGold;
	Font* m_OGold;

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