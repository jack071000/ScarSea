#pragma once
class Animation : public Object
{
private:
	std::vector<Sprite*> m_Anim;

	int m_Delay;
	int m_FrameCount;
	bool m_AutoPlay;
	int m_CurrentFrame;

public:
	Animation();
	~Animation();

	void AddFrame(std::wstring fileName);
	void AddContinueFrame(std::wstring fileName, int firstFrame, int lastFrame);

	void Init(int delay, bool play);
	void Update(float deltaTime);
	void Render();
};

