#pragma once
class CannonSpot;
class Suburb : public Stage
{
	MAPPOINT mapPoint[11];
	CannonSpot mapCannonSpot[10];

public:


public:
	Suburb();
	~Suburb();

	void SetMapPoint();
	void SetFishCannonPoint();

	void Update(float deltaTime);
	void Render();

	void ActivateButton();
	void DisableButton();
};