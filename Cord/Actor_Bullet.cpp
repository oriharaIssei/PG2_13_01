#include "Actor_Bullet.h"
#include "Actor_Player.h"

#include "CollisionManager.h"
#include "Novice.h"

void Bullet::Init() {
	isShot_ = true;
	
	pos_ = host_->GetPos();

	radius_ = 16.0f;
	speed_ = 16.0f;

	color_ = BLUE;
}

void Bullet::Update() {
	pos_.y -= speed_;
	if (pos_.y > 1280) {
		isShot_ = false;
	}
}

void Bullet::Draw() {
	if (!isShot_) {
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

void Bullet::OnCollision() {
	isShot_ = false;
}

Bullet::Bullet(Player* player_ptr) {
	host_ = std::unique_ptr<Player>(player_ptr);
	CollisionManager::SetBullet(this);
}

Bullet::~Bullet() {
}

Vector2 Bullet::GetPos() const {
	return pos_;
}

float Bullet::GetRadius() const {
	return radius_;
}

bool Bullet::GetIsShot() const {
	return isShot_;
}
