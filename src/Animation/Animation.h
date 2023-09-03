#pragma once

#include "SFML/Graphics.hpp"

class Animation {
public:
    Animation(const sf::Texture& texture, sf::Vector2i imageCount);

    ~Animation() = default;

    void Update(int row, float deltaTime);

    sf::IntRect intRect;

private:
    sf::Vector2i _imageCount;
    sf::Vector2i _currentImage;

    float _totalTime = 0.f;
    float _switchTime = 0.2f;
};


