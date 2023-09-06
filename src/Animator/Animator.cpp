#include "Animator.h"

Animator::Animator(const sf::Texture &texture, sf::Vector2i imageCount) {
    _imageCount = imageCount;

    intRect.width = int(texture.getSize().x / _imageCount.x);
    intRect.height = int(texture.getSize().y / _imageCount.y);
}

void Animator::update(int row, bool _shouldFlipAnimation, float deltaTime) {
    _totalTime += deltaTime;
    _currentImage.y = row;

    if (_totalTime >= _switchTime) {
        _totalTime = 0;
        _currentImage.x++;

        if (_currentImage.x >= _imageCount.x) {
            _currentImage.x = 0;
        }
    }

    intRect.top = _currentImage.y * intRect.height;

    if (_shouldFlipAnimation) {
        intRect.left = (_currentImage.x + 1) * abs(intRect.width);
        intRect.width = -abs(intRect.width);
    } else {
        intRect.left = _currentImage.x * intRect.width;
        intRect.width = abs(intRect.width);
    }
}
