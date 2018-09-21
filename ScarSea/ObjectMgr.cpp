#include "stdafx.h"
#include "ObjectMgr.h"



ObjectMgr::ObjectMgr()
{
}

ObjectMgr::~ObjectMgr()
{
}

void ObjectMgr::Release()
{
	for (auto iter = m_Objects.begin(); iter != m_Objects.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	m_Objects.clear();

	m_Enemys.clear();
	m_Bullets.clear();
}

void ObjectMgr::Update(float deltaTime)
{
	/*업데이트 하기 전에 삭제부터*/
	for (auto iter = m_Objects.begin(); iter != m_Objects.end();)
	{
		if ((*iter)->GetDestroy())
		{
			Object* temp = (*iter);
			iter = m_Objects.erase(iter);
			m_Enemys.remove(temp);
			m_Bullets.remove(temp);
			SAFE_DELETE(temp);
		}
		else
		{
			++iter;
		}
	}

	for (auto iter = m_Bullets.begin(); iter != m_Bullets.end(); ++iter)
	{
		for (auto iter2 = m_Enemys.begin(); iter2 != m_Enemys.end(); ++iter2)
		{
			RECT rect;
			if (IntersectRect(&rect, &(*iter)->m_Collision, &(*iter2)->m_Collision))
			{
				(*iter)->OnCollision((*iter2));
				(*iter2)->OnCollision((*iter));

				//return;
			}
		}
	}

	for (auto iter = m_Objects.begin(); iter != m_Objects.end(); ++iter)
	{
		(*iter)->Update(deltaTime);
	}

}

void ObjectMgr::Render()
{
 	m_Objects.sort(stLISTsort());

	for (auto iter = m_Objects.begin(); iter != m_Objects.end(); ++iter)
	{
		(*iter)->Render();
	}
}

void ObjectMgr::KeepObject(Object * obj)
{
	if (obj)
		m_Objects.push_back(obj);
	else
		MessageBox(NULL, L"오브젝트 추가 실패", NULL, MB_OK);
}

void ObjectMgr::RemoveObject(Object * obj)
{
	if (obj)
		obj->SetDestroy(true);
}
