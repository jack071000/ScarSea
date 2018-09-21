#pragma once
#include <algorithm>



#define ObjMgr ObjectMgr::GetInst()
class ObjectMgr : public Singleton<ObjectMgr>
{
public:
	std::list<Object*> m_Objects;
	std::list<Object*> m_Enemys;
	std::list<Object*> m_Bullets;

	struct stLISTsort
	{
		bool operator() (const Object *pObject1, const Object *pObject2) const
		{
			if (pObject1->m_Layer < pObject2->m_Layer)
				return TRUE;

			return FALSE;
		}
	};

public:
	ObjectMgr();
	~ObjectMgr();

	void Release();
	void Update(float deltaTime);
	void Render();


	

public:
	void KeepObject(Object* obj);
	void RemoveObject(Object* obj);

};

