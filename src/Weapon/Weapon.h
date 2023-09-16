#pragma once

#include "SFML/Graphics.hpp"

class Weapon {
public:
    Weapon() = default;

    ~Weapon() = default;

    void update();

    sf::Sprite &getSprite();

    void setTexture(const sf::Texture &texture);

    void setPosition(const sf::Vector2f &position);

private:
    sf::Sprite _sprite;

    sf::Texture _texture;
};
