#pragma once
#define ObjMgr ObjectMgr::GetInst()
class ObjectMgr : public Singleton<ObjectMgr>
{
public:
	std::list<Object*> m_Objects;
	std::list<Object*> m_Enemys;
	std::list<Object*> m_Bullets;

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

