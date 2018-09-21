#pragma once

#define PMgr PlayerMgr::GetInst()->GetPlayer()

class Player;
class PlayerMgr : public Singleton<PlayerMgr>
{
	Player* player;

public:
	PlayerMgr();
	~PlayerMgr();

	Player* GetPlayer() { return player; }
};

