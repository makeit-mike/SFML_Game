#include "StdAfx.h"
#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject() { _isLoaded = false; }

VisibleGameObject::~VisibleGameObject() { }

void VisibleGameObject::Load(sf::Texture& texture, std::string filename) {
	if (!_image.loadFromFile(filename)) {
		_filename = "";
		_isLoaded = false;
		std::cout << "issue loading texture";
		return;
	}

	_filename = filename;
	texture.loadFromImage(_image);
	_sprite.setTexture(texture);
	_sprite.scale(6, 6);
	_isLoaded = true;
}
void VisibleGameObject::Draw(sf::RenderWindow& renderWindow)
{
	if (_isLoaded)
	{
		renderWindow.draw(_sprite);
	}
}

void VisibleGameObject::Update(float elapsedTime, sf::RenderWindow& rw) {

}

void VisibleGameObject::SetPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}

sf::Vector2f VisibleGameObject::GetPosition() const {
	return _isLoaded ? _sprite.getPosition() : sf::Vector2f();
}

sf::Sprite& VisibleGameObject::GetSprite() {
	return _sprite;
}

bool VisibleGameObject::IsLoaded() const {
	return _isLoaded;
}
