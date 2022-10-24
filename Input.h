#pragma once
#include <Windows.h>
#include <wrl.h>
#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>

class Input
{
public:
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	void Initialize(HINSTANCE hInstance,HWND hwnd);

	void Update();

private:
	// キーボードデバイスの生成
	ComPtr<IDirectInputDevice8> keyboard;
};