#include "stdafx.h"
#include "Stage.h"


Stage::Stage()
	: m_iLeftTime(60)
	, m_iLeftWave(0)
	, m_Time(0)
{
	m_LeftWaveTime[0] = new Font();
	m_LeftWaveTime[1] = new Font();
	m_LeftWave = new Font();
	m_Shop = new Shop();

	ObjMgr->KeepObject(m_LeftWaveTime[0]); //���� �ð�
	ObjMgr->KeepObject(m_LeftWaveTime[1]); //���� �ð�
	ObjMgr->KeepObject(m_LeftWave); //���� ���̺�
	ObjMgr->KeepObject(m_Shop); //����
}

Stage::~Stage()
{
}

void Stage::Update(float deltaTime)
{
}

void Stage::Render()
{
}
