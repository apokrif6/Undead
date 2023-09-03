#include "Player.h"

sf::Sprite &Player::getSprite() {
    return _sprite;
}

void Player::setTexture(const sf::Texture &texture) {
    _texture = texture;

    _sprite.setTexture(texture);

    _sprite.setScale(2.f, 2.f);
}

void Player::move(sf::Vector2f direction) {
    _sprite.move(direction * _speed);
}

void Player::playAnimation(Animation &animation, float deltaTime) {
    animation.Update(0, deltaTime);

    _sprite.setTextureRect(animation.intRect);
}
