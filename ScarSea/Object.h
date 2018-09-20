#pragma once
class Object
{
public:
	LPDIRECT3DDEVICE9 m_pDev;
	Object* m_Parent;

	Matrix m_wMat;
	Vec2 m_Position;
	Vec2 m_Scale;
	float m_Rotation;

	bool m_Destroy;
	RECT m_Collision;

	bool m_Visible;

public:
	Object();
	~Object();
	

protected:
	Matrix GetMatrix();

public:
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void OnCollision(Object* other);

public:	
	void Translate(float x, float y);
	void SetScale(float x, float y);
	void SetPosition(float x, float y);
	void Rotate(float r);
	void SetDestroy(bool destroy) { m_Destroy = destroy; }
	void SetParent(Object* parent);
public:
	bool GetDestroy() { return m_Destroy; }
};