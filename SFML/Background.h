#pragma once
#include "BackgroundObject.h"

class Background : public BackgroundObject
{
public:
	Background();
	~Background();
	void Draw(sf::RenderWindow& rw);

private:
	sf::Texture texture_background;
};