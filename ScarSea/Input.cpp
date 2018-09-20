#include "stdafx.h"
#include "Input.h"


Input::Input()
	: m_MousePosition(0.f,0.f)
	, m_bCurrentState(false)
	, m_bPrevState(false)
	, m_ButtonDown(false)
{
	ZeroMemory(&m_CurrentState, sizeof(m_CurrentState));
	ZeroMemory(&m_PrevState, sizeof(m_PrevState));
}

Input::~Input()
{
}

void Input::Update()
{
	KeyBoardUpdate();
	MouseUpdate();
}

void Input::ButtonDown(bool down)
{
	m_ButtonDown = down;
}

KeyState Input::GetKey(int key)
{
	m_bPrevState = m_PrevState[key];
	m_bCurrentState = m_CurrentState[key];

	if (m_bPrevState == true && m_bCurrentState == true)
		return KeyState::PRESS;

	else if (m_bPrevState == true && m_bCurrentState == false)
		return KeyState::UP;

	else if (m_bPrevState == false && m_bCurrentState == true)
		return KeyState::DOWN;

	return KeyState::NONE;
}

void Input::KeyBoardUpdate()
{
	for (int i = 0; i < 256; i++)
	{
		m_PrevState[i] = m_CurrentState[i];
		m_CurrentState[i] = static_cast<bool>(GetAsyncKeyState(i));
	}
}

void Input::MouseUpdate()
{
	POINT point;
	GetCursorPos(&point);

	m_MousePosition.x = (float)(point.x);
	m_MousePosition.y = (float)(point.y);
}