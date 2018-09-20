#pragma once
class Player;
class Shop : public Object
{
private:
	Player * player;

	Sprite * m_ClamImage;
	Sprite * m_CoralImage;
	Sprite * m_AnemoneImage;

	Sprite* m_PushButton;
	bool m_bPushedButton;

public:
	Shop();
	~Shop();

	void Update(float deltaTime);
	void Render();
};