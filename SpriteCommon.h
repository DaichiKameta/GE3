#pragma once
#include <d3d12.h>
#include <wrl.h>
#include <string>

#include "DirectXCommon.h"

class SpriteCommon
{
public:// メンバ関数
	// 初期化
	void Initialize(DirectXCommon* _dxCommon);

	// 描画
	void PreDraw();

	// Getter
	DirectXCommon* GetDirectXCommon() { return dxCommon; }

private:// メンバ変数
	DirectXCommon* dxCommon;

	// パイプラインステート
	Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState;
	// ルートシグネチャ
	Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature;
};

