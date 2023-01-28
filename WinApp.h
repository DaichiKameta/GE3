#pragma once
#include <Windows.h>

// WindowsAPI
class WinApp
{
public: // �ÓI�����o�֐�
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public:
	// �E�B���h�E����
	static const int window_width = 1280;  // ����

	// �E�B���h�E�c��
	static const int window_height = 720;  // �c��

// �����o�֐�
public:
	// ������
	void Initialize();

	// ���b�Z�[�W�̏���
	bool ProcessMssage();

	// 
	void Finalize();

	// Getter
	HWND GetHwnd() const { return hwnd; }
	HINSTANCE GetHInstance() const { return w.hInstance; }

// �����o�ϐ�
private:
	// �E�B���h�E�n���h��
	HWND hwnd = nullptr;
	// �E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};
};

