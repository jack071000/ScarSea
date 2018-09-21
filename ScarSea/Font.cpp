#include "stdafx.h"
#include "Font.h"


Font::Font()
	: m_Frame(0)
{
	m_Font = new Animation();
	m_Font->AddContinueFrame(L"Painting/Font/", 0, 9);
	m_Font->Init(0, 0);
	m_Font->SetParent(this);
}

Font::~Font()
{
}

void Font::Update(float deltaTime)
{
	m_Font->SetFrame(m_Frame);
	m_Font->Update(deltaTime);
}

void Font::Render()
{
	m_Font->Render();
}
