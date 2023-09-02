#pragma once

#include "SFML/Graphics.hpp"
#include "../Managers/AssetManager/AssetManager.h"
#include "../Managers/InputManager/InputManager.h"
#include "../Player/Player.h"
#include "memory"

struct GameData {
    sf::RenderWindow renderWindow;
    AssetManager assetManager;
    InputManager inputManager;

    explicit GameData(InputManager input) : inputManager(input) {}
};

class Game {
public:
    Game(int screenWidth, int screenHeight, const std::string &gameTitle);

    ~Game() = default;

private:
    void Start();

    const float m_updateRate = 0.016;

    sf::Clock m_clock;

    std::shared_ptr<GameData> mr_gameData;

    Player m_player;
};
