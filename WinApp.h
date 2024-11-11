#pragma once
#include"Windows.h"
class WinApp
{
public://静的メンバ変数
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	//初期化
public://メンバ変数
	void Initialiize();
	//更新
	void Update();
};

