#pragma once
#include <Windows.h>

// WindowsAPI
class WinApp
{
public: // 静的メンバ関数
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public:
	// ウィンドウ横幅
	static const int window_width = 1280;  // 横幅

	// ウィンドウ縦幅
	static const int window_height = 720;  // 縦幅

// メンバ関数
public:
	// 初期化
	void Initialize();

	// メッセージの処理
	bool ProcessMssage();

	// 
	void Finalize();

	// Getter
	HWND GetHwnd() const { return hwnd; }
	HINSTANCE GetHInstance() const { return w.hInstance; }

// メンバ変数
private:
	// ウィンドウハンドル
	HWND hwnd = nullptr;
	// ウィンドウクラスの設定
	WNDCLASSEX w{};
};

