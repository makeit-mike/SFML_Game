#pragma once
#include "visiblegameobject.h"
class GameBall :
	public VisibleGameObject
{
public:
	GameBall();
	virtual ~GameBall();

private: 
	sf::Texture texture;
};

