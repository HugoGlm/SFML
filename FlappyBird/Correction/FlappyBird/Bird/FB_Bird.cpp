#include "FB_Bird.h"
#include "../../Math/Mathf.h"
#include "../../Time/Time.h"
#include "../../Input/Input.h"

#pragma region constructor
FB_Bird::FB_Bird()
{
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	if (texture->loadFromFile("C:/Users/GUIL2804/source/repos/P1-O3D-cpp/SFML/FlappyBird/FlappyBirdBg/flappy.png"))
	{
		sprite->setTexture(*texture);
	}
	sprite->setOrigin(sf::Vector2f(0, 0));
	sprite->setScale(sf::Vector2f(BIRD_SCALE, BIRD_SCALE));
	drawable = sprite;
}
FB_Bird::~FB_Bird()
{
	delete sprite;
	sprite = nullptr;
	delete texture;
	texture = nullptr;
}
#pragma endregion

#pragma region override
void FB_Bird::OnUpdate()
{
	if (isDead)
		return;
	sprite->setPosition(Mathf::Lerp(sprite->getPosition(), sprite->getPosition() + sf::Vector2f(0, GRAVITY), BIRD_SPEED_GRAVITY * Time::deltaTime));
	if (sprite->getPosition().y <= 0 || sprite->getPosition().y >= windowSize.y - sprite->getGlobalBounds().height)
	{
		Die();
		return;
	}
	const float _elapsed = lastjumpTimer.getElapsedTime().asSeconds();
	if (Input::IsKeyDown(sf::Keyboard::Space))
	{
		sprite->setRotation(-15.0f);
		sprite->setPosition(sprite->getPosition() - sf::Vector2f(0, BIRD_JUMP_FORCE));
		lastjumpTimer.restart();
	}
	else if (_elapsed > 0.2f && _elapsed < 0.5f)
		sprite->setRotation(0);
	else if (_elapsed > 0.6f)
		sprite->setRotation(15.0f);
}
void FB_Bird::OnCollisionEnter(GameObject* _other)
{
	Die();
}
void FB_Bird::Die()
{
	if (isDead)
		return;
	isDead = true;
	OnDie.Invoke();
}
sf::FloatRect FB_Bird::GetGlobalBounds() const
{
	return sprite->getGlobalBounds();
}
sf::Vector2f FB_Bird::Position() const
{
	return sprite->getPosition();
}
void FB_Bird::SetWindowSize(const sf::Vector2f& _size)
{
	windowSize = _size;
}
#pragma endregion

