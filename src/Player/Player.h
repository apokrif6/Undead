#pragma once

#include "SFML/Graphics.hpp"

#define PLAYER_TEXTURE_NAME "Player"
#define PLAYER_TEXTURE_FILE_NAME "../resources/img/test_player.png"

class Player {
public:
    Player() = default;

    ~Player() = default;

    void MoveLeft();

    void MoveRight();

    void MoveDown();

    void MoveUp();

    void SetTexture(const sf::Texture &texture);

    sf::Sprite &GetSprite();

private:
    sf::Sprite _sprite;

    float _speed = 10.f;
};
