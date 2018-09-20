#pragma once
class MainScreen : public Object
{
	Sprite * m_BackGround;

public:
	MainScreen();
	~MainScreen();

	void Update(float deltaTime);
	void Render();
};