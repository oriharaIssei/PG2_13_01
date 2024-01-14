#pragma once

#include "Actor_Player.h"
#include "Actor_Bullet.h"
#include "Actor_Enemy.h"

#include "vector"

class CollisionManager {
public:
	static void Update();
private:
	static Player* player_;
	static std::vector<Bullet*> bullets_;
	static std::vector<Enemy*> enemies_;
public:
	static void SetPlayer(Player* player);
	static void SetBullet(Bullet* bullet);
	static void SetEnemy(Enemy* enemy);
public:
	CollisionManager() = delete;
};