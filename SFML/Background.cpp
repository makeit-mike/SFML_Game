#include "StdAfx.h"
#include "Background.h"
#include "Game.h"


Background::Background()
{
	Load(Background::texture_background, "images/grass.png");
	assert(IsLoaded());

}

Background::~Background()
{
}

void Background::Draw(sf::RenderWindow& rw)
{
	BackgroundObject::Draw(rw);
}