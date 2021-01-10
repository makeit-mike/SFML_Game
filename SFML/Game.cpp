#include "Game.h"
#include "stdafx.h"
#include "MainMenu.h"
#include "SplashScreen.h"

void Game::Start(void) {
	if (_gameState != GameState::Uninitialized) return;

	//Startclock.restart();
	
	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Beans!", sf::Style::Titlebar | sf::Style::Close);
	_mainWindow.setFramerateLimit(60);
	_mainWindow.setVerticalSyncEnabled(true);

	//sf::View view(sf::FloatRect(0.f, 0.f, 1000.f, 600.f));
	//// move the view at point (200, 200)
	//view.setCenter(200.f, 200.f);

	//// move the view by an offset of (100, 100) (so its final position is (300, 300))
	//view.move(100.f, 100.f);
	//// activate it
	//_mainWindow.setView(view);

	//Background* background = new Background();
	//_backgroundManager.Add("firstScreen", background);


	//Dynamically create objects
	Player* player1 = new Player();
	player1->SetPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));
	_gameObjectManager.Add("Player", player1);

	GameBall* ball = new GameBall();
	ball->SetPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) - 15);
	_gameObjectManager.Add("Ball", ball);

	//Sets gamestate on first load
	_gameState = Game::GameState::ShowingSplash;

	sf::Clock clock;
	float elapsedTime = 0.0f;

	while (!IsExiting()) {
		sf::Event currentEvent;
		while (_mainWindow.pollEvent(currentEvent)) {
			switch (_gameState)
			{
			case Game::GameState::Uninitialized:
				break;
			case Game::GameState::ShowingSplash:
				ShowSplashScreen();
				break;
			case Game::GameState::Paused:
				break;
			case Game::GameState::ShowingMenu:
				ShowMenu();
				break;
			case Game::GameState::Playing:
				elapsedTime = clock.getElapsedTime().asSeconds();
				_mainWindow.clear(sf::Color(10, 10, 10));

				//_backgroundManager.UpdateAll(elapsedTime, _mainWindow);
				//_backgroundManager.DrawAll(_mainWindow);

				_gameObjectManager.UpdateAll(elapsedTime, _mainWindow);
				_gameObjectManager.DrawAll(_mainWindow);

				_mainWindow.display();
				if (currentEvent.type == sf::Event::Closed)
					_gameState = Game::GameState::Exiting;
				if (currentEvent.type == sf::Event::KeyPressed)
					if (currentEvent.key.code == sf::Keyboard::Escape) ShowMenu();
				break;
			case Game::GameState::Exiting:
				_mainWindow.close();
				return;
			default:
				break;
			}
		}
	}
	_mainWindow.close();
}

bool Game::IsExiting() {
	return (_gameState == Game::GameState::Exiting);
}

void Game::GameLoop() {
	
}
sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}

#pragma region GameLoops
void Game::PlayingLoop(sf::Event currentEvent) {
	
}
void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.show(_mainWindow);
	_gameState = Game::GameState::ShowingMenu;
}
void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result)
	{
	case MainMenu::Exit:
		_gameState = Game::GameState::Exiting;
		break;
	case MainMenu::Play:
		_gameState = Game::GameState::Playing;
		break;
	}
}
#pragma endregion

Game::GameState Game::_gameState = GameState::Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
//BackgroundManager Game::_backgroundManager;
