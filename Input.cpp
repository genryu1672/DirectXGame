//#define DIRECTINPUT_VERSION  0x0800//DirectInputのバージョン指定
#include "Input.h"
#include <cassert>
//#include<wrl.h>
//#include<dinput.h>
//using namespace Microsoft::WRL;
void Input::Initialize(HINSTANCE hInstance, HWND hwnd)
{
	HRESULT result;
	
	//DirectInputの初期化(一度だけ行う処理)
	IDirectInput8* directInput = nullptr;
	result = DirectInput8Create(
		hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8,
		(void**)&directInput, nullptr);
	assert(SUCCEEDED(result));

	//キーボードデバイスの生成
	//IDirectInputDevice8* keyboard = nullptr;
	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));

	//入力データ形式のセット
	result = keyboard->SetDataFormat(&c_dfDIKeyboard);//標準形式
	assert(SUCCEEDED(result));

	//排他制御レベルのセット
	result = keyboard->SetCooperativeLevel(

		hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));
}

void Input::Update()
{
	//キーボード情報の取得開始
	keyboard->Acquire();

	//全キーの入力状態を取得する
	//BYTE key[256] = {};
	keyboard->GetDeviceState(sizeof(key), key);
}

bool Input::PushKey(BYTE keyNumber)
{
	//指定キーを押していればtrueを返す
	if (key[keyNumber])
	{
		return true;
	}
	
	//座標操作
	//if (key[DIK_UP] || key[DIK_DOWN] || key[DIK_RIGHT] || key[DIK_LEFT])
	//{
	//	if (key[DIK_UP]) { object3ds[0].position.y += 1.0f; }
	//	else if(key[DIK_DOWN]) { object3ds[0].position.y -= 1.0f; }
	//	
	//	if (key[DIK_RIGHT]) { object3ds[0].position.x += 1.0f; }
	//	else if (key[DIK_LEFT]) { object3ds[0].position.x -= 1.0f; }
	//
	//}

	//そうでなければfalseを返す
	return false;
}
