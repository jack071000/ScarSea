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
		//��ư�� �����ְ�
	}
	else
	{
		/*���� �׸���� ���̰�*/
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
		//��������
		if (INPUT->GetButtonDown())
		{
			//�÷��̾�� + ����� ����� ������ True 
			//�÷��̾ ��ġ
		}
	}

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_CoralImage->GetRect()))
	{
		//��ȣ ����
		if (INPUT->GetButtonDown())
		{

		}
	}

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_AnemoneImage->GetRect()))
	{
		//������ ����
		if (INPUT->GetButtonDown())
		{

		}
	}

}

void Shop::Render()
{
}
