#include "StdAfx.h"
#include "BackgroundObject.h"

BackgroundObject::BackgroundObject() { _isLoaded = false; }

BackgroundObject::~BackgroundObject() { }

void BackgroundObject::Load(sf::Texture& texture, std::string filename) {
	if (!_image.loadFromFile(filename)) {
		_filename = "";
		_isLoaded = false;
		std::cout << "issue loading texture";
		return;
	}

	_filename = filename;
	texture.loadFromImage(_image);
	_sprite.setTexture(texture);
	_sprite.scale(2, 2);
	_isLoaded = true;
}
void BackgroundObject::Draw(sf::RenderWindow& renderWindow)
{
	if (_isLoaded)
	{
		renderWindow.draw(_sprite);
	}
}

void BackgroundObject::Update(float elapsedTime, sf::RenderWindow& rw) {

}

void BackgroundObject::SetPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}

sf::Vector2f BackgroundObject::GetPosition() const {
	return _isLoaded ? _sprite.getPosition() : sf::Vector2f();
}

sf::Sprite& BackgroundObject::GetSprite() {
	return _sprite;
}

bool BackgroundObject::IsLoaded() const {
	return _isLoaded;
}
