#pragma once
#include "VisibleGameObject.h"


class Player : public VisibleGameObject {
public:
	Player();
	~Player();

	void Update(float elapsedTime, sf::RenderWindow& rw);
	void CheckWindowCollisions(sf::RenderWindow& rw);
	void Draw(sf::RenderWindow& rw);

	float GetVelocity() const;

private:
	float _velocity; //-- left, ++ right
	float _maxVelocity;
	sf::Texture texture;
	sf::Vector2f _movements;
};

