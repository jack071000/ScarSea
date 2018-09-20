#pragma once
class Font : public Object
{
private:
	Animation* m_Font;

public:
	Font();
	~Font();

	void Update(float deltaTime);
	void Render();
};

