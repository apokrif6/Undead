#include "Game.h"

Game::Game(int screenWidth, int screenHeight, const std::string &gameTitle) {
    InputManager inputManager(_player);

    _gameData = std::make_shared<GameData>(inputManager);

    initPlayer();

    _gameData->renderWindow.create(sf::VideoMode(screenWidth, screenHeight), gameTitle);

    start();
}

void Game::start() {
    float newTime, frameTime;

    float currentTime = _clock.getElapsedTime().asSeconds();

    float accumulator = 0.f;

    while (_gameData->renderWindow.isOpen()) {
        newTime = _clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= _updateRate) {
            _gameData->inputManager.handleInput();

            accumulator -= _updateRate;
        }

        sf::Event event{};

        while (_gameData->renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _gameData->renderWindow.close();
        }

        _gameData->renderWindow.clear();
        _gameData->renderWindow.draw(_player.getSprite());
        _gameData->renderWindow.display();
    }
}

void Game::initPlayer() {
    _gameData->assetManager.loadTexture(PLAYER_TEXTURE_NAME, PLAYER_TEXTURE_FILE_NAME);

    _player.setTexture(_gameData->assetManager.getTexture(PLAYER_TEXTURE_NAME));;
}
