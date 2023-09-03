#include "Player.h"

sf::Sprite &Player::getSprite() {
    return _sprite;
}

void Player::setTexture(const sf::Texture &texture) {
    _sprite.setTexture(texture);

    _sprite.setScale(0.3f, 0.3f);
}

void Player::move(sf::Vector2f direction) {
    _sprite.move(direction * _speed);
}
