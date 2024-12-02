#pragma once
#include<d3d12.h>
#include<dxgi1_6.h>
#include<wrl.h>
#include"WinApp.h"
//前方宣言
class WinApp;

class DirectXCommon
{
public://メンバ変数
	//初期化
	void Initialize(WinApp*winApp);

private://関数

	//デバイスの生成

	/// <summary>
	/// 
	/// </summary>
	void CreateDevice();

	//コマンド関連の生成
	void CreateCommand();

	//スワップチェーンの生成
	void CreateSwapChain();
	
	//深度バッファの生成
	void DepthCreateBufferView();
	
	//各種デスクリプタヒープの生成
	void CreateAllDescriptorHeap();
	
	//レンダーターゲットビューの初期化
	void RTVInitialize();

	//深度ステンシルビューの初期化
	void StencilInitialize();

	//フェンスの生成
	void CreateFence();

	//ビューポート矩形の初期化
	void ViewPortInitilize();

	//シザリング矩形の生成
	void CreateSizaling();

	//DCXコンパイラの生成
	void CreateDCX();

	//ImGuiの初期化
	void ImGuiInitilize();

private://メンバ変数

	HRESULT hr;

	//WindosAPI
	WinApp* winApp = nullptr;

	//名前空間
	Microsoft::WRL::ComPtr<ID3D12Device> device = nullptr;
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

	//コマンド関連の初期化
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue = nullptr;
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator = nullptr;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList = nullptr;

	//スワップチェーンの生成
	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain = nullptr;
};

