#include "StdAfx.h"
#include "GameBall.h"

GameBall::GameBall()
{
	Load(texture, "images/bro.png");

	GetSprite().setPosition(15, 15);
}

GameBall::~GameBall()
{
}
