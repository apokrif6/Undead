#include "Game.h"
#include "SFML/Graphics.hpp"

Game::Game(int screenWidth, int screenHeight, const std::string &gameTitle) {
    InputManager inputManager(_player);

    _gameData = std::make_shared<GameData>(inputManager);

    initPlayer();

    _gameData->renderWindow.create(sf::VideoMode(screenWidth, screenHeight), gameTitle);

    start();
}

void Game::start() {
    _gameData->soundManager.playBackgroundTheme();

    while (_gameData->renderWindow.isOpen()) {
        float deltaTime = _clock.getElapsedTime().asSeconds();

        while (deltaTime >= _updateRate) {
            _gameData->inputManager.handleInput();

            _player.update(deltaTime);

            _player.getWeapon().update();

            deltaTime = _clock.restart().asSeconds();
        }

        sf::Event event{};

        while (_gameData->renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _gameData->renderWindow.close();
        }

        _gameData->renderWindow.clear(sf::Color::White);
        _gameData->renderWindow.draw(_player.getCollision());
        _gameData->renderWindow.draw(_player.getSprite());
        _gameData->renderWindow.draw(_player.getWeapon().getSprite());
        _gameData->renderWindow.display();
    }
}

void Game::initPlayer() {
    _gameData->assetManager.loadTexture(PLAYER_TEXTURE_NAME, PLAYER_TEXTURE_FILE_NAME);

    _player.setTexture(_gameData->assetManager.getTexture(PLAYER_TEXTURE_NAME));

    _player.setAnimator(Animator(_gameData->assetManager.getTexture(PLAYER_TEXTURE_NAME),
                                 sf::Vector2i(6, 10)));

    _gameData->assetManager.loadTexture(WEAPON_TEXTURE_NAME, WEAPON_TEXTURE_FILE_NAME);

    _player.createWeapon(_gameData->assetManager.getTexture(WEAPON_TEXTURE_NAME));
}
