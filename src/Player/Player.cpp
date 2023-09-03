#include "Player.h"

sf::Sprite &Player::getSprite() {
    return _sprite;
}

void Player::setTexture(const sf::Texture &texture) {
    _sprite.setTexture(texture);

    Tile playerTile;

    _sprite.setTextureRect(sf::IntRect(18,22, playerTile.width, playerTile.height));

    _sprite.setScale(2.f, 2.f);
}

void Player::move(sf::Vector2f direction) {
    _sprite.move(direction * _speed);
}
