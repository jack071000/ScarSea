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
	Sprite* m_LeftTime; //남은 시간 UI
	Sprite* m_BackGround; //배경
	Sprite* m_Wave; //남은 Wave UI

	Shop* m_Shop; //상점

	int m_iWave1EnemyCount;
	int m_iWave2EnemyCount;
	int m_iWave3EnemyCount;

protected:
	Font * m_LeftWaveTime[2]; //다음 웨이브까지 남은 시간
	Font* m_LeftWave; //남은 웨이브

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