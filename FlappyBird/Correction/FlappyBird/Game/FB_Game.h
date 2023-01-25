#pragma once
#include "../../Window/Window.h"

#define TIME_FOR_SPAWN 1.5f

class FB_Game : public Window
{
#pragma region f/p
private:
	bool isStarted = false;
	class FB_Image* background = nullptr;
	class FB_Bird* bird = nullptr;
	class FB_Score* score = nullptr;
	sf::Clock spawnerClock = sf::Clock();
#pragma endregion
#pragma region constructor
public:
	FB_Game();
	~FB_Game();
#pragma endregion
#pragma region methods
private:
	void OnBirdDied();
	void Start();
	void InitBackGround();
	void SpawnPipe();
#pragma endregion
#pragma region override
protected:
	void OnDraw();
	void OnUpdate();
	void InitMenus() override;
	virtual void OnReceiveEvent(const sf::Event& _event) override;
#pragma endregion

};

