#pragma once
#include "Vector2.h"

class Enemy {
public:
	void Init();
	void Update();
	void Draw();
	void OnCollision();

	Enemy();
	~Enemy();

private:
	Vector2 pos_;
	float radius_;
	float speed_;

	unsigned int color_;

	static bool isAlive_;
public:
	Vector2 GetPos()const;
	float GetRadius()const;
	static bool GetIsAlive();
};