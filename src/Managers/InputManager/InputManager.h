#pragma once

#include "SFML/Graphics.hpp"
#include "../../Player/Player.h"

class InputManager {
public:
    explicit InputManager(Player &playerRef) : mr_player(playerRef) {}

    ~InputManager() = default;

    void HandleInput();

private:
    Player &mr_player;
};
