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


    sf::RectangleShape playBtn;
    playBtn.setSize(sf::Vector2f(Game::SCREEN_WIDTH, 380));
    playBtn.setOutlineColor(sf::Color::Red);
    playBtn.setOutlineThickness(5);
    playBtn.setPosition(0, 145);
    window.draw(playBtn);

    sf::RectangleShape exitBtn;
    exitBtn.setSize(sf::Vector2f(Game::SCREEN_WIDTH, 380));
    exitBtn.setOutlineColor(sf::Color::Blue);
    exitBtn.setOutlineThickness(5);
    exitBtn.setPosition(0, 560);
    window.draw(exitBtn);

    //Setup clickable regions
    //Play menu item coordinates
    MenuItem playButton;
    playButton.rect.top = 145;
    playButton.rect.height = 380;
    playButton.rect.left = 0;
    playButton.rect.width = 1023;
    playButton.action = Play;

    //Exit menu item coordinates
    MenuItem exitButton;
    exitButton.rect.left = 0;
    exitButton.rect.width = 1023;
    exitButton.rect.top = 383;
    exitButton.rect.height = 560;
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
        if (menuItemRect.height > y
            && menuItemRect.top < y
            && menuItemRect.left < x
            && menuItemRect.width > x)
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
                return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
            }
            if (menuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
        }
    }
}