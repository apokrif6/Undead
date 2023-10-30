#pragma once

#include "../Managers/AssetManager/AssetManager.h"
#include "../Managers/InputManager/InputManager.h"
#include "../Managers/SoundManager/SoundManager.h"
#include "../Player/Player.h"
#include "memory"

struct GameData {
    sf::RenderWindow renderWindow;
    AssetManager assetManager;
    InputManager inputManager;
    SoundManager soundManager;

    explicit GameData(InputManager input) : inputManager(input) {}
};

class Game {
public:
    Game(int screenWidth, int screenHeight, const std::string &gameTitle);

    ~Game() = default;

private:
    void start();

    const float _updateRate = 0.016;

    sf::Clock _clock;

    std::shared_ptr<GameData> _gameData;

    Player _player;

    void initPlayer();
};
