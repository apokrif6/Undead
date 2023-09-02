#include "Player.h"

Player::Player() {
    mr_shape.setRadius(40.f);
    mr_shape.setFillColor(sf::Color::Green);
}

void Player::MoveLeft() {
    mr_shape.move(sf::Vector2f(-m_speed, 0.f));
}

void Player::MoveRight() {
    mr_shape.move(sf::Vector2f(m_speed, 0.f));
}

void Player::MoveDown() {
    mr_shape.move(sf::Vector2f(0.0f, m_speed));
}

void Player::MoveUp() {
    mr_shape.move(sf::Vector2f(0.0f, -m_speed));
}

sf::CircleShape &Player::GetShape() {
    return mr_shape;
}
