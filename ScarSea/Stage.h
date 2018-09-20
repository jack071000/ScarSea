#pragma once
class Stage : public Object
{
protected:
	Sprite* m_BackGround; //배경
	Font* m_LeftWaveTime[2]; //다음 웨이브까지 남은 시간
	Font* m_LeftWave; //남은 웨이브
	Shop* m_Shop; //상점

	int m_iLeftWave;
	int m_iLeftTime;
	float m_Time;

public:
	Stage();
	~Stage();

	void Update(float deltaTime);
	void Render();
};