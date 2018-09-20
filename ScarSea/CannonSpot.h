#pragma once
class CannonSpot : public Object
{
private:
	Sprite* m_PlusButton;
	bool m_ButtonActive;

	bool m_Intalled;

	Cannon* m_Cannon;
	D3DXVECTOR2 Pos;

public:
	CannonSpot();
	~CannonSpot();

public:
	void ActivateButton() { m_ButtonActive = true; }
	void DisableButton() { m_ButtonActive = false; }
	bool GetButtonActive() { return m_ButtonActive; }

public:
	void Update(float deltaTime);
	void Render();
};

