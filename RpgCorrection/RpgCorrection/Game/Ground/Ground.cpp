#include "Ground.h"
#include "../../Core/Utils/Debug/Debug.h"
#include "../../Core/Window/Window.h"

#pragma region const
Game::Ground::Ground(const sf::Vector2f& _size, const sf::Color& _color) : super()
{
    rectShape = new sf::RectangleShape(_size);
    rectShape->setFillColor(_color);
}
#pragma endregion

#pragma region override
void Game::Ground::SetPosition(const sf::Vector2f& _position)
{
    checkLow((rectShape != nullptr), "[Ground] => rectShape is nullptr")
        rectShape->setPosition(_position);
}
void Game::Ground::SetOrigin(const sf::Vector2f& _origin)
{
    checkLow((rectShape != nullptr), "[Ground] => rectShape is nullptr")
        rectShape->setOrigin(_origin);
}
void Game::Ground::SetScale(const sf::Vector2f& _scale)
{
    checkLow((rectShape != nullptr), "[Ground] => rectShape is nullptr")
        rectShape->setScale(_scale);
}
sf::Vector2f Game::Ground::Position() const
{
    check((rectShape != nullptr), "[Ground] => rectShape is nullptr", sf::Vector2f(0, 0))
        return rectShape->getPosition();
}
sf::Vector2f Game::Ground::Origin() const
{
    check((rectShape != nullptr), "[Ground] => rectShape is nullptr", sf::Vector2f(0, 0))
        return rectShape->getOrigin();
}
sf::Vector2f Game::Ground::Scale() const
{
    check((rectShape != nullptr), "[Ground] => rectShape is nullptr", sf::Vector2f(0, 0))
        return rectShape->getScale();
}
sf::FloatRect Game::Ground::GlobalBounds() const
{
    check((rectShape != nullptr), "[Ground] => rectShape is nullptr", sf::FloatRect(0, 0, 0, 0))
        return rectShape->getGlobalBounds();
}
bool Game::Ground::IsValid() const
{
    return rectShape != nullptr;
}
void Game::Ground::Draw(Core::Window* _owner)
{
    checkLow((rectShape != nullptr), "[Ground] => rectShape is nullptr")
        _owner->Draw(rectShape);
}
#pragma endregion