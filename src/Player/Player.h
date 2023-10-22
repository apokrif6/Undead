#pragma once

#include "SFML/Graphics.hpp"
#include "../Animator/Animator.h"
#include "../Weapon/Weapon.h"
#include "memory"


class Player {
public:
    Player();

    ~Player() = default;

    void update(float deltaTime);

    void move(sf::Vector2f direction);

    void setTexture(const sf::Texture &texture);

    void setAnimator(Animator animator);

    sf::Sprite &getSprite();

    void createWeapon(const sf::Texture &texture);

    Weapon &getWeapon() const { return *_weapon; }

private:
    sf::Sprite _sprite;

    sf::Texture _texture;

    std::unique_ptr<Animator> _animator;

    float _speed = 3.f;

    int _animationRow = 0;

    bool _shouldFlipAnimation = false;

    std::unique_ptr<Weapon> _weapon;
};
