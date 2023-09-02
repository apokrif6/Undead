#pragma once

#include "SFML/Graphics.hpp"

class Player {
public:
    Player();

    ~Player() = default;

    void MoveLeft();

    void MoveRight();

    void MoveDown();

    void MoveUp();

    sf::CircleShape &GetShape();

private:
    sf::CircleShape mr_shape;

    float m_speed = 10.f;
};
