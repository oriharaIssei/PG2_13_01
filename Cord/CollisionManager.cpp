#include "CollisionManager.h"

Player* CollisionManager::player_;
std::vector<Bullet*> CollisionManager::bullets_;
std::vector<Enemy*> CollisionManager::enemies_;

void CollisionManager::Update() {
	//
	//	Player - Enemies
	//
	if (player_->GetIsAlive()) {
		for (auto enemy : enemies_) {
			if (!enemy->GetIsAlive()) {
				continue;
			}
			Vector2 distance;
			distance.x = player_->GetPos().x - enemy->GetPos().x;
			distance.y = player_->GetPos().y - enemy->GetPos().y;

			if (distance.x * distance.x + distance.y * distance.y < ((player_->GetRadius() + enemy->GetRadius()) * (player_->GetRadius() + enemy->GetRadius()))) {
				player_->OnCollision();
			}
		}
	}

	//
	//	Enemies - Bullets
	//

	for (auto enemy : enemies_) {
		if (!Enemy::GetIsAlive()) {
			return;
		}
		for (auto bullet : bullets_) {
			if (!bullet->GetIsShot()) {
				continue;
			}

			Vector2 distance;
			distance.x = bullet->GetPos().x - enemy->GetPos().x;
			distance.y = bullet->GetPos().y - enemy->GetPos().y;

			if (distance.x * distance.x + distance.y * distance.y < ((bullet->GetRadius() + enemy->GetRadius()) * (bullet->GetRadius() + enemy->GetRadius()))) {
				bullet->OnCollision();
				enemy->OnCollision();

				if (!bullet->GetIsShot()) {
					break;
				}
			}
		}
	}
}

void CollisionManager::SetPlayer(Player* player) {
	player_ = player;
}

void CollisionManager::SetBullet(Bullet* bullet) {
	bullets_.push_back(bullet);
}

void CollisionManager::SetEnemy(Enemy* enemy) {
	enemies_.push_back(enemy);
}
