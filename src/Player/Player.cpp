#include "Player.h"

void Player::MoveLeft() {
    _sprite.move(sf::Vector2f(-_speed, 0.f));
}

void Player::MoveRight() {
    _sprite.move(sf::Vector2f(_speed, 0.f));
}

void Player::MoveDown() {
    _sprite.move(sf::Vector2f(0.0f, _speed));
}

void Player::MoveUp() {
    _sprite.move(sf::Vector2f(0.0f, -_speed));
}

sf::Sprite &Player::GetSprite() {
    return _sprite;
}

void Player::SetTexture(const sf::Texture &texture) {
    _sprite.setTexture(texture);

    _sprite.setScale(0.3f, 0.3f);
}
