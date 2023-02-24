#include "GamePad.h"
#include <iostream>
#include <format>
#include <SFML/Graphics.hpp>

#define THUMB_MAX 32768.0f
#define TRIGGER_MAX 255.0f

#pragma region constructor
GamePad::GamePad(int _index)
{
	index = _index;
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	ZeroMemory(&vibration, sizeof(XINPUT_STATE));
	XInputGetState(index, &state);
}
GamePad::~GamePad()
{
	ClearVibration();
}
#pragma endregion

#pragma region methods
void GamePad::Update()
{
	bool _connected = isConnected;
	isConnected = XInputGetState(index, &state) == ERROR_SUCCESS;
	/*if (!_connected && isConnected)
		std::cout << std::format("controller ({}) connected !", index) << std::endl;
	else if (_connected && !isConnected)
		std::cout << std::format("controller ({}) disconnected !", index) << std::endl;*/
	XInputSetState(index, &vibration);
}
void GamePad::ClearVibration()
{
	if (!isConnected)
		return;
	vibration = XINPUT_VIBRATION();
}
void GamePad::SetVibration(float _left, float _right)
{
	if (!isConnected)
		return;
	vibration.wLeftMotorSpeed = static_cast<WORD>(_left);
	vibration.wRightMotorSpeed = static_cast<WORD>(_right);
}
bool GamePad::GetVibrationSpeed(float& _left, float& _right)
{
	if (!isConnected)
	{
		_left = _right = 0;
		return false;
	}
	_left = static_cast<float>(vibration.wLeftMotorSpeed);
	_right = static_cast<float>(vibration.wRightMotorSpeed);
	return true;
}
bool GamePad::GetDeltaRightThumb(float& _x, float& _y)
{
	if (!isConnected)
	{
		_x = _y = 0;
		return false;
	}
	_x = static_cast<float>(state.Gamepad.sThumbRX / THUMB_MAX);
	_y = static_cast<float>(state.Gamepad.sThumbRY / THUMB_MAX);
	return _x > 0 || _y > 0;
}
bool GamePad::GetDeltaLeftThumb(float& _x, float& _y)
{
	if (!isConnected)
	{
		_x = _y = 0;
		return false;
	}
	_x = static_cast<float>(state.Gamepad.sThumbLX / THUMB_MAX);
	_y = static_cast<float>(state.Gamepad.sThumbLY / THUMB_MAX);
	return _x > 0 || _y > 0;
}
bool GamePad::GetDeltaTrigger(float& _left, float& _right)
{
	if (!isConnected)
	{
		_left = _right = 0;
		return false;
	}
	_left = static_cast<float>(state.Gamepad.bLeftTrigger / TRIGGER_MAX);
	_right = static_cast<float>(state.Gamepad.bRightTrigger / TRIGGER_MAX);
	return _left > 0 || _right > 0;
}
bool GamePad::IsConnected() const
{
	return isConnected;
}
#pragma endregion
