#include <iostream>
#include "Player.h"

Player::Player() {
    _collision->setOutlineColor(sf::Color::Red);
    _collision->setOutlineThickness(1);

}

void Player::setTexture(const sf::Texture &texture) {
    _texture = texture;

    _sprite.setTexture(texture);

    _sprite.setScale(2.f, 2.f);
}

void Player::setAnimator(Animator animator) {
    _animator = std::make_unique<Animator>(animator);
}

void Player::move(sf::Vector2f direction) {
    _sprite.move(direction * _speed);

    if (direction.x == 0 && direction.y == 0) {
        _animationRow = 0;
    } else if (direction.y > 0) {
        _animationRow = 3;
        _shouldFlipAnimation = false;
    } else if (direction.y < 0) {
        _animationRow = 5;
        _shouldFlipAnimation = true;
    } else if (direction.x > 0) {
        _animationRow = 4;
        _shouldFlipAnimation = false;
    } else if (direction.x < 0) {
        _animationRow = 4;
        _shouldFlipAnimation = true;
    }
}

void Player::update(float deltaTime) {
    _animator->update(_animationRow, _shouldFlipAnimation, deltaTime);

    _sprite.setTextureRect(_animator->intRect);

    _weapon->setPosition(_sprite.getPosition() + sf::Vector2f{50, 50});

    _collision->setSize({getSprite().getGlobalBounds().getSize().x / 2, getSprite().getGlobalBounds().getSize().y / 2});
    _collision->setPosition(_sprite.getPosition() + sf::Vector2f{25, 40});
}

void Player::createWeapon(const sf::Texture &texture) {
    _weapon->setTexture(texture);
}


