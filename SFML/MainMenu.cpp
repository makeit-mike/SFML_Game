#include "stdafx.h"
#include "MainMenu.h"
#include "Game.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
    //Load menu image from file.
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    image.loadFromFile("images/MainMenu.png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    window.draw(sprite);

    sf::RectangleShape playBtn;
    int playTop = 160;
    int playHeight = 180;
    int playWidth = Game::SCREEN_WIDTH;
    int playLeft = 0;
    playBtn.setSize(sf::Vector2f(Game::SCREEN_WIDTH, playHeight));
    playBtn.setOutlineColor(sf::Color::Green);
    playBtn.setOutlineThickness(5);
    playBtn.setFillColor(sf::Color::Transparent);
    playBtn.setPosition(0, playTop);
    window.draw(playBtn);
    MenuItem playButton;
    playButton.rect.top = playTop;
    playButton.rect.height = playHeight;
    playButton.rect.left = playLeft;
    playButton.rect.width = playWidth;
    playButton.action = Play;

    sf::RectangleShape exitBtn;
    int exitTop = 460;
    int exitHeight = 180;
    int exitWidth = Game::SCREEN_WIDTH;
    int exitLeft = 0;
    exitBtn.setSize(sf::Vector2f(Game::SCREEN_WIDTH, exitHeight));
    exitBtn.setOutlineColor(sf::Color::Green);
    exitBtn.setOutlineThickness(5);
    exitBtn.setFillColor(sf::Color::Transparent);
    exitBtn.setPosition(0, exitTop);
    window.draw(exitBtn);    
    MenuItem exitButton;
    exitButton.rect.top = exitTop;
    exitButton.rect.height = exitHeight;
    exitButton.rect.left = exitLeft;
    exitButton.rect.width = exitWidth;
    exitButton.action = Exit;

    _menuItems.push_back(playButton);
    _menuItems.push_back(exitButton);
    //window.draw(sprite);
    window.display();
    return GetMenuResponse(window);
}
MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
    std::list<MenuItem>::iterator it;
    for (it = _menuItems.begin(); it != _menuItems.end(); it++)
    {
        sf::Rect<int> menuItemRect = (*it).rect;
       /* std::cout << "item H(>y): " << menuItemRect.height << 
                    " T(<y): " << menuItemRect.top << 
                    " L(<x): " << menuItemRect.left << 
                    " W(>x): " << menuItemRect.width << std::endl;*/
        if (menuItemRect.height + menuItemRect.top > y
            && menuItemRect.top < y)/*
            && menuItemRect.left < x
            && menuItemRect.width > x)*/
        {
            return (*it).action;
        }
    }
    return Nothing;
}
MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
    sf::Event menuEvent;
    while (42 != 43)
    {
        while (window.pollEvent(menuEvent))
        {
            if (menuEvent.type == sf::Event::MouseButtonPressed)
            {
                std::cout << "X: " << menuEvent.mouseButton.x << " Y: " <<  menuEvent.mouseButton.y << std::endl;
                return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
            }
            if (menuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
        }
    }
}