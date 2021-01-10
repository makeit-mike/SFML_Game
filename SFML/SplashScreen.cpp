#include "StdAfx.h"
#include "SplashScreen.h"

void SplashScreen::show(sf::RenderWindow & renderWindow) {
	sf::Image image;
	image.loadFromFile("images\\Winter.png");
	
	sf::Texture texture;
	texture.loadFromImage(image);
	
	sf::Sprite sprite;
	sprite.setTexture(texture);

	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;
	while (true) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed) return;
		}
	}

}