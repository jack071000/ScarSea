#include "stdafx.h"
#include "Sprite.h"
#include"Texture.h"
#include"ResourceMgr.h"

Sprite::Sprite()
	: m_pSp(Renderer::GetInst()->GetSprite())
	, m_Size(0.f,0.f)
{
	m_pSp->AddRef();
	SetRect(&m_Rect, 0, 0, 0, 0);
}

Sprite::~Sprite()
{
}

bool Sprite::Init(std::wstring fileName)
{
	m_Texture = ResourceMgr::GetInst()->CreateTextureFromFile(fileName);
	if (m_Texture)
	{
		m_Size = m_Texture->GetSize();
		SetRect(&m_Rect, 0, 0, m_Size.x, m_Size.y);
		return true;
	}
	else
		return false;
}

void Sprite::SetRectSize(float x, float y)
{
	SetRect(&m_Rect, 0, 0, (m_Size.x / x),(m_Size.y / y));
}

Sprite * Sprite::Create(std::wstring fileName)
{
	auto sprite = new (std::nothrow) Sprite();
	if (sprite && sprite->Init(fileName))
	{
		return sprite;
	}
	else
	{
		SAFE_DELETE(sprite);
		return NULL;
	}
}

void Sprite::Render()
{
	if (m_Parent)
	{
		SetRect(&m_Parent->m_Collision, m_Parent->m_Position.x - m_Size.x / 2, m_Parent->m_Position.y - m_Size.y / 2,
			m_Parent->m_Position.x + m_Size.x / 2, m_Parent->m_Position.y + m_Size.y / 2);
	}
	
 	m_Collision.left = (long)(m_Position.x - m_Size.x / 2);
	m_Collision.right = (long)(m_Position.x + m_Size.x / 2);

	m_Collision.top = (long)(m_Position.y - m_Size.y / 2);
	m_Collision.bottom = (long)(m_Position.y + m_Size.y / 2);


	if (m_Visible == false)
		return;

 	m_pSp->Begin(D3DXSPRITE_ALPHABLEND);
	m_pSp->SetTransform(&GetMatrix());
	m_pSp->Draw(m_Texture->GetTexture(), &m_Rect, &D3DXVECTOR3(m_Size.x / 2, m_Size.y / 2, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	m_pSp->End();
}