#pragma once

#include "SFML/Graphics.hpp"

class InputManager {
public:
    explicit InputManager(sf::CircleShape &shapeRef) : r_shape(shapeRef) {}

    ~InputManager() = default;

    void HandleInput();

private:
    sf::CircleShape& r_shape;
};
