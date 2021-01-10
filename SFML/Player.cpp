#include "StdAfx.h"
#include "Player.h"
#include "Game.h"

Player::Player()//constructor
    : _velocity(0), _maxVelocity(600.0f)
{
    Load(Player::texture, "images/Player.png");
    assert(IsLoaded());

    GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().y / 2);
}
Player::~Player()//deconstructor
{
}

void Player::Draw(sf::RenderWindow& rw)
{
    VisibleGameObject::Draw(rw);
}

float Player::GetVelocity() const
{
    return _velocity;
}

void Player::Update(float elapsedTime, sf::RenderWindow& rw) {
    float speed = 0.5f;
    sf::Vector2f movements = { 0.0f,0.0f };

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        movements.x =  -speed * elapsedTime;//left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        movements.x = speed * elapsedTime;//right
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        movements.y = speed * elapsedTime;//down
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        movements.y = -speed * elapsedTime;//up
    }
    sf::Vector2f pos = this->GetPosition();
    GetSprite().move(movements);
    _movements = movements;

    CheckWindowCollisions(rw);
}
void Player::CheckWindowCollisions(sf::RenderWindow& rw) {
    sf::FloatRect playerDimensions = GetSprite().getGlobalBounds();
    if (playerDimensions.left <= 0.0f) { //left bound
        SetPosition(0, GetPosition().y);
    }
    else if (playerDimensions.left - playerDimensions.width >= rw.getSize().x) { //right bound
        SetPosition(rw.getSize().x - playerDimensions.width, GetPosition().y);
    }

    if (playerDimensions.top <= 0.0f) { //top bound 
        SetPosition(GetPosition().x, 0);
    }
    else if (playerDimensions.top - playerDimensions.height >= rw.getSize().y) { //bottom bound
        SetPosition(GetPosition().x, rw.getSize().y - playerDimensions.height - 10);
    }
}