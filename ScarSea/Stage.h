#pragma once
class Stage : public Object
{
protected:
	Sprite* m_BackGround; //���
	Font* m_LeftWaveTime[2]; //���� ���̺���� ���� �ð�
	Font* m_LeftWave; //���� ���̺�
	Shop* m_Shop; //����

	int m_iLeftWave;
	int m_iLeftTime;
	float m_Time;

public:
	Stage();
	~Stage();

	void Update(float deltaTime);
	void Render();
};