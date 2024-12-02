#pragma once
#include<d3d12.h>
#include<dxgi1_6.h>
#include<wrl.h>
class DirectXCommon
{
public://メンバ変数
	//初期化
	void Initialize();

private://関数

	//デバイスの生成
	void CreateDevice();

	//コマンド関連の生成
	void CreateCommand();

	//スワップチェーンの生成
	void CreateSwapChain();
	
	//深度バッファの生成
	void DepthCreateBufferView();
	//各種デスクリプタヒープの生成
};

