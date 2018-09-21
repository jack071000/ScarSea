#pragma once
class Font : public Object
{
private:
	Animation* m_Font;
	int m_Frame;

public:
	Font();
	~Font();

	void SetFrame(int frame) { m_Frame = frame; }
	void Update(float deltaTime);
	void Render();
};

