#pragma once

#include "SFML/Graphics.hpp"
#include "../Animator/Animator.h"
#include "memory"

#define PLAYER_TEXTURE_NAME "Player"
#define PLAYER_TEXTURE_FILE_NAME "../resources/img/player.png"

class Player {
public:
    Player() = default;

    ~Player() = default;

    void update(float deltaTime);

    void move(sf::Vector2f direction);

    void setTexture(const sf::Texture &texture);

    void setAnimator(Animator animator);

    sf::Sprite &getSprite();

private:
    sf::Sprite _sprite;

    sf::Texture _texture;

    std::unique_ptr<Animator> _animator;

    float _speed = 3.f;

    int _animationRow = 0;

    bool _shouldFlipAnimation = false;
};
