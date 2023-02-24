#pragma once
#include <Windows.h>
#include <Xinput.h>
#pragma comment(lib, "Xinput.lib")

class GamePad
{
#pragma region f/p
private:
	bool isConnected = false;
	int index = 0;
	XINPUT_STATE state = XINPUT_STATE();
	XINPUT_VIBRATION vibration = XINPUT_VIBRATION();
#pragma endregion
#pragma region constructor
public:
	GamePad() = default;
	GamePad(int _index);
	~GamePad();
#pragma endregion
#pragma region methods
public:
	void Update();
	void ClearVibration();
	void SetVibration(float _left, float _right);
	bool GetVibrationSpeed(float& _left, float& _right);
	bool GetDeltaRightThumb(float& _x, float& _y);
	bool GetDeltaLeftThumb(float& _x, float& _y);
	bool GetDeltaTrigger(float& _left, float& _right);
	bool IsConnected() const;
#pragma endregion

};

