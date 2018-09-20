#include "stdafx.h"
#include "CollisionMgr.h"


CollisionMgr::CollisionMgr()
{
}


CollisionMgr::~CollisionMgr()
{
}

bool CollisionMgr::MouseWithBoxCollide(RECT rect)
{
	Vec2 Mouse = INPUT->GetMousePos();
	//printf("Mouse : %f %f\n", Mouse.x, Mouse.y);

	if (rect.left <= Mouse.x && Mouse.x <= rect.right)
	{
		if (rect.top <= Mouse.y && Mouse.y <= rect.bottom)
			return true;
	}

	return false;
}
