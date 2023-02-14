#pragma once
#include <SFML/Graphics.hpp>

class IPointerClickHandler
{
public:
    virtual ~IPointerClickHandler() = default;
    virtual void OnPointerClick(const sf::Event& _event) = 0;
};