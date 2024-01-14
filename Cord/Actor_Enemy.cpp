#include "Actor_Enemy.h"

#include "Novice.h"
#include "CollisionManager.h"

#include "random"

bool Enemy::isAlive_ = true;

void Enemy::Init() {
	radius_ = 36.0f;

	std::random_device rand;
	std::mt19937_64 gen(rand());
	std::uniform_real_distribution<float> randPosX(radius_, 1280.0f - radius_);
	std::uniform_real_distribution<float> randPosY(0.0f, 364.0f);

	pos_ = { randPosX(gen),randPosY(gen) };

	speed_ = 8.0f;

	color_ = RED;
}

void Enemy::Update() {
	pos_.x += speed_;

	if (pos_.x < radius_ || pos_.x > 1280 - radius_) {
		speed_ *= -1.0f;
	}
}

void Enemy::Draw() {
	if (!isAlive_) {
		return;
	}

	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f,
		color_,
		kFillModeSolid);
}

void Enemy::OnCollision() {
	isAlive_ = false;
}

Enemy::Enemy() {
	CollisionManager::SetEnemy(this);
}

Enemy::~Enemy() {
}

Vector2 Enemy::GetPos() const {
	return pos_;
}

float Enemy::GetRadius() const {
	return radius_;
}

bool Enemy::GetIsAlive() {
	return isAlive_;
}
