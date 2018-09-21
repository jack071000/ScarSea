#include "stdafx.h"
#include "Stage.h"


Stage::Stage()
	: m_iLeftTime(60)
	, m_iLeftWave(0)
	, m_STime(0)
	, m_Time(0)
	, m_Frame(60)
	, m_State(StageState::READY)
	, m_iTotalEnemy(0)
	, m_iWave1EnemyCount(0)
	, m_iWave2EnemyCount(0)
	, m_iWave3EnemyCount(0)
{
	m_LeftWaveTime[0] = new Font();
	m_LeftWaveTime[1] = new Font();
	m_LeftWave = new Font();
	m_Shop = new Shop();
	m_fTotalEnemy[0] = new Font();
	m_fTotalEnemy[1] = new Font();


	m_TotalEnemy = Sprite::Create(L"Painting/Enemy.png");
	m_LeftTime = Sprite::Create(L"Painting/Time.png");
	m_Wave = Sprite::Create(L"Painting/Wave.png");

	m_TotalEnemy->SetPosition(680, 30);
	m_LeftWave->SetPosition(530, 100);
	m_Wave->SetPosition(530, 30);
	m_LeftTime->SetPosition(330, 30);

	m_LeftWaveTime[0]->SetPosition(300, 100);
	m_LeftWaveTime[1]->SetPosition(360, 100);
	m_LeftWaveTime[0]->m_Layer = 2;
	m_LeftWaveTime[1]->m_Layer = 2;

	m_fTotalEnemy[0]->SetPosition(650, 100);
	m_fTotalEnemy[0]->m_Layer = 2;
	m_fTotalEnemy[1]->SetPosition(710, 100);
	m_fTotalEnemy[1]->m_Layer = 2;

	ObjMgr->KeepObject(m_Wave); //Wave UI
	ObjMgr->KeepObject(m_LeftTime); //남은 시간 UI
	ObjMgr->KeepObject(m_LeftWaveTime[0]); //남은 시간 폰트
	ObjMgr->KeepObject(m_LeftWaveTime[1]); //남은 시간 폰트
	ObjMgr->KeepObject(m_LeftWave); //남은 웨이브 폰트
	ObjMgr->KeepObject(m_Shop); //상점
	ObjMgr->KeepObject(m_TotalEnemy); //총 적 UI
	ObjMgr->KeepObject(m_fTotalEnemy[0]); //적 수 폰트
	ObjMgr->KeepObject(m_fTotalEnemy[1]); //적 수 폰트
}

Stage::~Stage()
{
}

void Stage::Update(float deltaTime)
{
	switch (m_State)
	{
	case StageState::READY:
		m_fTotalEnemy[0]->SetFrame(m_iWave1EnemyCount / 10);
		m_fTotalEnemy[1]->SetFrame(m_iWave1EnemyCount % 10);

		m_iLeftWave = 3;
		if (m_Frame <= 0)
		{
			m_Frame = 60;
			m_State = StageState::WAVE1;
		}
		break;

	case StageState::WAVE1:
		m_fTotalEnemy[0]->SetFrame(m_iWave2EnemyCount / 10);
		m_fTotalEnemy[1]->SetFrame(m_iWave2EnemyCount % 10);

		m_iLeftWave = 2;
		if (m_Frame <= 0)
		{
			m_Frame = 60;
			m_State = StageState::WAVE2;
		}
		break;

	case StageState::WAVE2:
		m_fTotalEnemy[0]->SetFrame(m_iWave3EnemyCount / 10);
		m_fTotalEnemy[1]->SetFrame(m_iWave3EnemyCount % 10);

		m_iLeftWave = 1;
		if (m_Frame <= 0)
		{
			m_Frame = 60;
			m_State = StageState::WAVE3;
		}
		break;

	case StageState::WAVE3:
		m_iLeftWave = 0;
		if (m_Frame <= 0)
		{
			m_Frame = 60;
			m_State = StageState::NONE;
		}
		break;
	}

	m_STime ++;

	if (m_STime > 1)
	{
		m_Frame--;
		m_STime = 0;
	}
	
	m_LeftWaveTime[0]->SetFrame(m_Frame / 10);
	m_LeftWaveTime[1]->SetFrame(m_Frame % 10);
	m_LeftWave->SetFrame(m_iLeftWave);
	
}

void Stage::Render()
{
}
