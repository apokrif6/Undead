#pragma once

#include "SFML/Graphics.hpp"
#include "../Animation/Animation.h"

#define PLAYER_TEXTURE_NAME "Player"
#define PLAYER_TEXTURE_FILE_NAME "../resources/img/player.png"

class Player {
public:
    Player() = default;

    ~Player() = default;

    void playAnimation(Animation &animation, float deltaTime);

    void move(sf::Vector2f direction);

    void setTexture(const sf::Texture &texture);

    sf::Sprite &getSprite();

private:
    sf::Sprite _sprite;

    sf::Texture _texture;

    float _speed = 3.f;
};
