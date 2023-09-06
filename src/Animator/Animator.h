#pragma once

#include "SFML/Graphics.hpp"

class Animator {
public:
    Animator(const sf::Texture& texture, sf::Vector2i imageCount);

    ~Animator() = default;

    void update(int row, bool _shouldFlipAnimation, float deltaTime);

    sf::IntRect intRect;

private:
    sf::Vector2i _imageCount;
    sf::Vector2i _currentImage;

    float _totalTime = 0.f;
    float _switchTime = 0.2f;
};


