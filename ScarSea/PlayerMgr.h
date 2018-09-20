#pragma once
class Player;
class PlayerMgr : public Singleton<PlayerMgr>
{
	Player* player;

public:
	PlayerMgr();
	~PlayerMgr();

	Player* GetPlayer() { return player; }
};

