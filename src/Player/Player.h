#pragma once

#include "SFML/Graphics.hpp"

#define PLAYER_TEXTURE_NAME "Player"
#define PLAYER_TEXTURE_FILE_NAME "../resources/img/player.png"

struct Tile {
    int width;
    int height;
    //13, 65, 113, 161, 209, 257 px
    Tile() : width(13), height(21) {}
};

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
