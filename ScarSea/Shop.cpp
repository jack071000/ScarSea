#include "stdafx.h"
#include "Shop.h"


Shop::Shop()
	: m_bPushedButton(false)
{
	m_PushButton = Sprite::Create(L"Painting/PushButton.png");
	m_PushButton->SetPosition(1870, 300);

	m_AnemoneImage = Sprite::Create(L"Painting/AnemoneImage.png");
	m_AnemoneImage->m_Visible = false;
	m_AnemoneImage->SetPosition(1700, 400);

	m_ClamImage = Sprite::Create(L"Painting/ClamImage.png");
	m_ClamImage->m_Visible = false;
	m_ClamImage->SetPosition(1700, 550);

	m_CoralImage = Sprite::Create(L"Painting/CoralImage.png");
	m_CoralImage->m_Visible = false;
	m_CoralImage->SetPosition(1700, 700);
}

Shop::~Shop()
{
}

void Shop::Update(float deltaTime)
{
	printf("���� ���� �̹��� �浹 ���� : %ld , %ld , %ld , %ld\n", m_ClamImage->m_Collision.left, m_ClamImage->m_Collision.right, m_ClamImage->m_Collision.top, m_ClamImage->m_Collision.bottom);
	if (m_bPushedButton == false)
	{
		//��ư�� �����ְ�
		m_PushButton->m_Visible = true;

		m_AnemoneImage->m_Visible = false;
		m_ClamImage->m_Visible = false;
		m_CoralImage->m_Visible = false;
	}

	if(m_bPushedButton == true)
	{
		/*���� �׸���� ���̰�*/
		m_AnemoneImage->m_Visible = true;
		m_ClamImage->m_Visible = true;
		m_CoralImage->m_Visible = true;
	}

	//���� ��ư�� ������ ��
	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_PushButton->m_Collision))
	{
		//���� ��ư�� ������ �ʾҴٸ�
		if (m_bPushedButton == false)
		{
			if (INPUT->GetButtonDown())
			{
				m_bPushedButton = true;

				m_AnemoneImage->m_Visible = true;
				m_ClamImage->m_Visible = true;
				m_CoralImage->m_Visible = true;
				INPUT->ButtonDown(false);
			}
		}
		//�̹� ���� ��ư�� �����ٸ�
		else
		{
			if (INPUT->GetButtonDown())
			{
				m_PushButton->m_Visible = true;

				m_AnemoneImage->m_Visible = false;
				m_ClamImage->m_Visible = false;
				m_CoralImage->m_Visible = false;
				m_bPushedButton = false;

				PlayerMgr::GetInst()->GetPlayer()->m_Install = false;
				PlayerMgr::GetInst()->GetPlayer()->m_InstallCannonType = CANNONTYPE::NONE;
				INPUT->ButtonDown(false);
			}
		}
	}

	if (m_bPushedButton == false)
		return;

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_ClamImage->m_Collision))
	{
		//��������
		if (INPUT->GetButtonDown())
		{
			//�÷��̾�� + ����� ����� ������ True 
			//�÷��̾ ��ġ
			PlayerMgr::GetInst()->GetPlayer()->m_Install = true;
			PlayerMgr::GetInst()->GetPlayer()->m_InstallCannonType = CANNONTYPE::CLAM;
			INPUT->ButtonDown(false);
		}
	}

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_CoralImage->m_Collision))
	{
		//��ȣ ����
		if (INPUT->GetButtonDown())
		{

		}
	}

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_AnemoneImage->m_Collision))
	{
		//������ ����
		if (INPUT->GetButtonDown())
		{

		}
	}

}

void Shop::Render()
{
	m_PushButton->Render();

	m_ClamImage->Render();
	m_CoralImage->Render();
	m_AnemoneImage->Render();
}