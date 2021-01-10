#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Background.h"
#include "GameBall.h"
#include "GameObjectManager.h"
#include "BackgroundManager.h"

class Game
{
public:
    static void Start();
    static sf::RenderWindow& GetWindow();
    const static int SCREEN_WIDTH = 1280;
    const static int SCREEN_HEIGHT = 720;

private:
    static bool IsExiting();
    static void GameLoop(); 

    static void ShowSplashScreen();
    static void ShowMenu();
    static void PlayingLoop(sf::Event currentEvent);

    enum class GameState {
        Uninitialized, ShowingSplash, Paused,
        ShowingMenu, Playing, Exiting
    };

    static GameState _gameState;
    static sf::RenderWindow _mainWindow;

    static GameObjectManager _gameObjectManager;
    static BackgroundManager _backgroundManager;

};
