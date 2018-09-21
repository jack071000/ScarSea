#pragma once

enum class StageState
{
	READY,
	WAVE1,
	WAVE2,
	WAVE3,
	NONE
};

class Stage : public Object
{
protected:
	StageState m_State;
	Sprite* m_LeftTime; //���� �ð� UI
	Sprite* m_BackGround; //���
	Sprite* m_Wave; //���� Wave UI

	Shop* m_Shop; //����

	int m_iWave1EnemyCount;
	int m_iWave2EnemyCount;
	int m_iWave3EnemyCount;

protected:
	Font * m_LeftWaveTime[2]; //���� ���̺���� ���� �ð�
	Font* m_LeftWave; //���� ���̺�

protected:
	int m_iLeftWave;
	int m_iLeftTime;

	float m_STime;
	float m_Time;

	int m_Frame;

protected:
	Font * m_fTotalEnemy[2];
	Sprite * m_TotalEnemy;
	int m_iTotalEnemy;

public:
	Stage();
	~Stage();

	void Update(float deltaTime);
	void Render();
};