#include "Gif.h"
#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_GIF
#include "../Utils/stb_image.h"

#pragma region constructor
Core::Gif::Gif(const char* _path)
{
	FILE* _file = stbi__fopen(_path, "rb");
	stbi__context _context = stbi__context();
	stbi__start_file(&_context, _file);
	int* _delays = nullptr;
	int _numberFrames = 0, _comp = 0;
	void* _pixels = stbi__load_gif_main(&_context, &_delays, &size.x, &size.y, &_numberFrames, &_comp, STBI_rgb_alpha);
	sf::Image _image = sf::Image();
	int _step = size.x * size.y * 4;
	for (int i = 0; 1 < _numberFrames; i++)
	{
		_image.create(size.x, size.y, (const sf::Uint8*)_pixels + _step * i);
		sf::Texture _texture = sf::Texture();
		_texture.loadFromImage(_image);
		frames.push_back(std::tuple(_delays[i], _texture));
	}
	frameIterator = frames.begin();
	stbi_image_free(_pixels);
	if (_delays)
		stbi_image_free(_delays);
	fclose(_file);
	totalDelay = sf::Time::Zero;
	startTime = clock.getElapsedTime();
}
#pragma endregion

#pragma region methods
void Core::Gif::update(sf::Sprite& _sprite)
{
	sf::Time _delay = sf::milliseconds(std::get<0>(*frameIterator));
	while (startTime + totalDelay < clock.getElapsedTime())
	{
		frameIterator++;
		if (frameIterator == frames.end())
			frameIterator = frames.begin();
		totalDelay += _delay;
		_delay = sf::milliseconds(std::get<0>(*frameIterator));
	}
	_sprite.setTexture(std::get<1>(*frameIterator));
}
sf::Vector2i Core::Gif::GetSize() const
{
	return size;
}
#pragma endregion