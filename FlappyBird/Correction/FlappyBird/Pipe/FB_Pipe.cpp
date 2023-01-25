#include "FB_Pipe.h"
#include "../../Time/Time.h"
#include "../Manager/Texture/FB_TextureManager.h"
#include "../Manager/FB_GameObjectManager.h"

#pragma region constructor
FB_Pipe::FB_Pipe()
{
	sprite = new sf::Sprite();
	texture = FB_TextureManager::Instance()->Get("C:/Users/GUIL2804/source/repos/P1-O3D-cpp/SFML/FlappyBird/FlappyBirdBg/pipe.png");
	sprite->setTexture(*texture);
	sprite->scale(0.1f, 0.1f);
	drawable = sprite;
}
FB_Pipe::~FB_Pipe()
{
	delete sprite; 
	sprite = nullptr;
}
#pragma endregion

#pragma region methods
void FB_Pipe::Rotate()
{
	sprite->rotate(180);
}
void FB_Pipe::Move()
{
	SetPosition(sprite->getPosition() - sf::Vector2f(1, 0) * PIPE_SPEED * Time::deltaTime);
	if (!passedBird && sprite->getPosition().x <= -0.5f && onBirdPosition.IsValid())
	{
		onBirdPosition.Invoke();
		passedBird = true;
	}
	if (sprite->getPosition().x < (0 - GetGlobalBounds().width))
		FB_GameObjectManager::Instance()->Destroy(this);
}
void FB_Pipe::SetPosition(const sf::Vector2f& _position)
{
	sprite->setPosition(_position);
}
#pragma endregion

#pragma region override
sf::FloatRect FB_Pipe::GetGlobalBounds() const
{
	return sprite->getGlobalBounds();
}
sf::Vector2f FB_Pipe::Position() const
{
	return sprite->getPosition();
}
void FB_Pipe::OnUpdate()
{
	Move();
}
#pragma endregion


