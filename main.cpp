#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"

#include "SpriteCommon.h"
#include "Sprite.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

#pragma region 基盤システム初期化

    // WindowsAPIの初期化
    WinApp* winApp = nullptr;
    winApp = new WinApp();
    winApp->Initialize();


    // DirectX12初期化
    DirectXCommon* dxCommon = nullptr;
    dxCommon = new DirectXCommon();
    dxCommon->Initialize(winApp);

    //  入力初期化
    Input* input = nullptr;
    input = new Input();
    input->Initialize(winApp);

    // SpriteCommon
    SpriteCommon* spriteCommon = nullptr;
    spriteCommon = new SpriteCommon();
    spriteCommon->Initialize(dxCommon);

#pragma endregion

#pragma region 最初のシーン初期化

    // Sprite
    Sprite* sprite = nullptr;
    sprite = new Sprite();
    sprite->Initialize(spriteCommon);

#pragma endregion

    // ゲームループ
    while (true) {
        
#pragma region 基盤システム初期化
        // メッセージ処理
        if (winApp->ProcessMessage() == true) {
            // ゲームループを抜ける
            break;
        }

        // 入力の更新処理
        input->Update();
#pragma endregion

#pragma region 最初のシーン更新

#pragma endregion

        // 描画前処理
        dxCommon->PreDraw();

  
#pragma region 最初のシーン描画

        spriteCommon->PreDraw();
        sprite->Draw();

#pragma endregion
        // 描画後処理
        dxCommon->PostDraw();
    }

#pragma region 最初のシーン終了

    //sprite
    delete sprite;
    sprite = nullptr;

#pragma endregion

#pragma region 基盤システム終了
    // spriteCommon
    delete spriteCommon;
    spriteCommon = nullptr;

    // input
    delete input;
    input = nullptr;

    // DxCommon
    delete dxCommon;
    dxCommon = nullptr;

    // WinApp
    winApp->Finalize();
    delete winApp;
    winApp = nullptr;

#pragma endregion

    return 0;
}