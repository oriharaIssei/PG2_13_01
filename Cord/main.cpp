#include <Novice.h>

#include "Actor_Player.h"
#include "Actor_Bullet.h"
#include "Actor_Enemy.h"

#include "CollisionManager.h"

const char kWindowTitle[] = "LC1B_08_オリハライッセイ_";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Player* player = new Player();
	player->Init();
	

	Enemy* enemy[4];
	for (int i = 0; i < 4; i++) {
		enemy[i] = new Enemy();
		enemy[i]->Init();
	}


	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Update();
		for (int i = 0; i < 4; i++) {
			enemy[i]->Update();
		}
		CollisionManager::Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();
		for (int i = 0; i < 4; i++) {
			enemy[i]->Draw();
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
