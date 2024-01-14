#pragma once

#include "Actor_Bullet.h"
#include "Vector2.h"

#include "vector"

class Player {
public:
    void Init();
    void Update();
    void Draw();
    void OnCollision();

    Player();
    ~Player();

private:
    void Move();
    void Shot();
private:
    Vector2 pos_;
    float radius_;
    float speed_;

    bool isAlive_;

    std::vector<Bullet*> bullets_;

    int fullCoolTime_;
    int coolTime_;

    unsigned int color_;
public:
    Vector2 GetPos()const;
    float GetRadius()const;
    bool GetIsAlive()const;
};