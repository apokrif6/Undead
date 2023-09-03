#pragma once

#include "SFML/Graphics.hpp"

#define PLAYER_TEXTURE_NAME "Player"
#define PLAYER_TEXTURE_FILE_NAME "../resources/img/test_player.png"

class Player {
public:
    Player() = default;

    ~Player() = default;

    void move(sf::Vector2f direction);

    void setTexture(const sf::Texture &texture);

    sf::Sprite &getSprite();

private:
    sf::Sprite _sprite;

    float _speed = 5.f;
};
