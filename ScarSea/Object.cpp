#include "stdafx.h"
#include "Object.h"


Object::Object() : 
	m_pDev(Renderer::GetInst()->GetDevice())
	, m_Position(0.f,0.f)
	, m_Rotation(0.f)
	, m_Scale(1.f,1.f)
	, m_Destroy(0)
	, m_Parent(NULL)
	, m_Visible(true)
	, m_Layer(0)
	, m_Name(L"")
{
	m_pDev->AddRef();
	D3DXMatrixIdentity(&m_wMat);
}


Object::~Object()
{
}

Matrix  Object::GetMatrix()
{
	D3DXMatrixTransformation2D(&m_wMat, NULL, NULL, &m_Scale, NULL, m_Rotation, &m_Position);

	if (m_Parent)
		m_wMat *= m_Parent->GetMatrix();

	return m_wMat;
}

void Object::Translate(float x, float y)
{
	m_Position.x += x;
	m_Position.y += y;
}

void Object::SetScale(float x, float y)
{
	m_Scale.x = x;
	m_Scale.y = y;
}

void Object::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Object::Rotate(float r)
{
	m_Rotation += r;
}

void Object::SetParent(Object * parent)
{
	m_Parent = parent;
}

void Object::Update(float deltaTime)
{
}

void Object::Render()
{
}

void Object::OnCollision(Object * other)
{
}