#include "Actor_Player.h"

#include "Novice.h"

#include "CollisionManager.h"

void Player::Init() {
	isAlive_ = true;

	pos_ = { 640.0f,652.0f };

	radius_ = 24.0f;

	speed_ = 8.0f;

	fullCoolTime_ = 16;
	coolTime_ = fullCoolTime_;

	color_ = BLUE;

	if (!bullets_.empty()) {
		bullets_.clear();
	}
}

void Player::Update() {
	if (!isAlive_) {
		return;
	}

	coolTime_ = coolTime_ >= 0 ? --coolTime_ : 0;

	Move();
	Shot();

	for (auto bullet : bullets_) {
		if (!bullet->GetIsShot()) {
			continue;
		}
		bullet->Update();
	}
}

void Player::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(radius_),
			static_cast<int>(radius_),
			0.0f,
			color_,
			kFillModeSolid);
	}

	for (auto bullet : bullets_) {
		if (!bullet->GetIsShot()) {
			continue;
		}
		bullet->Draw();
	}
}

void Player::OnCollision() {
	isAlive_ = false;
}

Player::Player() {
	CollisionManager::SetPlayer(this);
}

Player::~Player() {
	if (bullets_.empty()) {
		return;
	}
	bullets_.clear();
}

void Player::Move() {
	if (Novice::CheckHitKey(DIK_A)) {
		pos_.x -= speed_;
	}
	if (Novice::CheckHitKey(DIK_D)) {
		pos_.x += speed_;
	}
	if (Novice::CheckHitKey(DIK_W)) {
		pos_.y -= speed_;
	}
	if (Novice::CheckHitKey(DIK_S)) {
		pos_.y += speed_;
	}
}

void Player::Shot() {
	if (Novice::CheckHitKey(DIK_SPACE)) {
		if (coolTime_ <= 0) {
			coolTime_ = fullCoolTime_;
			for (auto bullet : bullets_) {
				if (!bullet->GetIsShot()) {
					bullet->Init();
					return;
				}
			}
			Bullet* newBullet = new Bullet(this);
			newBullet->Init();
			bullets_.push_back(newBullet);
		}
	}
}

Vector2 Player::GetPos() const {
	return pos_;
}

float Player::GetRadius() const {
	return radius_;
}

bool Player::GetIsAlive() const {
	return isAlive_;
}
