#include "stdafx.h"
#include "Shop.h"


Shop::Shop()
{
}

Shop::~Shop()
{
}

void Shop::Update(float deltaTime)
{
	if (m_PushButton == false)
	{
		//버튼만 나와있게
	}
	else
	{
		/*상점 항목들이 보이게*/
	}

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_PushButton->GetRect()))
	{
		if (INPUT->GetButtonDown())
		{
			m_PushedButton = true;
		}
	}

	if (m_PushedButton == false)
		return;

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_ClamImage->GetRect()))
	{
		//조개대포
		if (INPUT->GetButtonDown())
		{
			//플레이어에게 + 모양을 띄우라는 변수를 True 
			//플레이어가 설치
		}
	}

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_CoralImage->GetRect()))
	{
		//산호 대포
		if (INPUT->GetButtonDown())
		{

		}
	}

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_AnemoneImage->GetRect()))
	{
		//말미잘 대포
		if (INPUT->GetButtonDown())
		{

		}
	}

}

void Shop::Render()
{
}
