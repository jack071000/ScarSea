#pragma once
class Intro : public Object
{
	Animation* m_AIntro;

public:
	Intro();
	~Intro();

	void Update(float deltaTime);
	void Render();
};

