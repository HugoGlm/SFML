#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow _window(sf::VideoMode(900, 800), "First SFML");
	_window.setFramerateLimit(60);
	sf::RectangleShape _shape(sf::Vector2f(200, 100));
	sf::RectangleShape _shape2(sf::Vector2f(200, 100));
	_shape.setPosition(450, 400);
	_shape2.setPosition(650, 400);
	sf::Clock _clock;
	float _deltaTime = 0.0f;
	const float speed = 5.0f;

	while (_window.isOpen())
	{
		sf::Time _elapsed = _clock.restart();
		_deltaTime = _elapsed.asSeconds();
		std::cout << _deltaTime << std::endl;
		// Event
		sf::Event _event;
		while (_window.pollEvent(_event))
		{
			if (_event.type == sf::Event::Closed)
				_window.close();
			if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape)
				_window.close();
		}
		// Update
		_shape.setOrigin(100, 50);
		_shape.setPosition(_shape.getPosition() + sf::Vector2f(1, 0) * speed * _deltaTime);
		if (_shape.getGlobalBounds().intersects(_shape2.getGlobalBounds()))
		{
			std::cout << "collision enter" << std::endl;
		}
		// Draw
		_window.clear();

		/*if (_window.hasFocus())
			_window.draw(_shape);*/

		_window.draw(_shape);
		_window.draw(_shape2);
		// Display elements
		_window.display();
	}
}