#include "Game.h"

Game::Game(int screenWidth, int screenHeight, const std::string &gameTitle) {
    InputManager inputManager(_player);

    _gameData = std::make_shared<GameData>(inputManager);

    InitPlayer();

    _gameData->renderWindow.create(sf::VideoMode(screenWidth, screenHeight), gameTitle);

    Start();
}

void Game::Start() {
    float newTime, frameTime;

    float currentTime = _clock.getElapsedTime().asSeconds();

    float accumulator = 0.f;

    while (_gameData->renderWindow.isOpen()) {
        newTime = _clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= _updateRate) {
            _gameData->inputManager.HandleInput();

            accumulator -= _updateRate;
        }

        sf::Event event{};

        while (_gameData->renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _gameData->renderWindow.close();
        }

        _gameData->renderWindow.clear();
        _gameData->renderWindow.draw(_player.GetSprite());
        _gameData->renderWindow.display();
    }
}

void Game::InitPlayer() {
    _gameData->assetManager.LoadTexture(PLAYER_TEXTURE_NAME, PLAYER_TEXTURE_FILE_NAME);

    _player.SetTexture(_gameData->assetManager.GetTexture(PLAYER_TEXTURE_NAME));;
}
