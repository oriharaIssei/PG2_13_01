#pragma once
#include "Vector2.h"

#include "memory"

class Player;
//=================================
// 発射される弾
//=================================
class Bullet {
public:
    void Init();
    void Update();
    void Draw();
    
    void OnCollision();

    Bullet(Player* player_ptr);
    ~Bullet();

private:
    std::unique_ptr<Player> host_;

    Vector2 pos_;
    float radius_;
    float speed_;
    unsigned int color_;

    bool isShot_;
public:
    Vector2 GetPos()const;
    float GetRadius()const;

    bool GetIsShot()const;
};