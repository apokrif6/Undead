#include "Game.h"

Game::Game(int screenWidth, int screenHeight, const std::string &gameTitle) {
    InputManager inputManager(m_player);

    mr_gameData = std::make_shared<GameData>(inputManager);

    mr_gameData->renderWindow.create(sf::VideoMode(screenWidth, screenHeight), gameTitle);

    Start();
}

void Game::Start() {
    float newTime, frameTime;

    float currentTime = m_clock.getElapsedTime().asSeconds();

    float accumulator = 0.f;

    while (mr_gameData->renderWindow.isOpen()) {
        newTime = m_clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= m_updateRate) {
            //TODO
            //create tick logic

            mr_gameData->inputManager.HandleInput();

            accumulator -= m_updateRate;
        }

        sf::Event event{};

        while (mr_gameData->renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                mr_gameData->renderWindow.close();
        }

        mr_gameData->renderWindow.clear();
        mr_gameData->renderWindow.draw(m_player.GetShape());
        mr_gameData->renderWindow.display();
    }
}
