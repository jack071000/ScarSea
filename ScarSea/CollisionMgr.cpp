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

	if (Mouse.x > rect.left && Mouse.x < rect.right)
		if (Mouse.y > rect.top && Mouse.y < rect.bottom)
			return true;

	return false;
}
