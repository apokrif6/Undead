#pragma once

#include "SFML/Graphics.hpp"
#include "../../Player/Player.h"

class InputManager {
public:
    explicit InputManager(Player &playerRef) : _player(playerRef) {}

    ~InputManager() = default;

    void handleInput();

private:
    Player &_player;
};
