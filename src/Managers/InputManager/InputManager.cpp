#include "InputManager.h"
#include "cmath"

void InputManager::handleInput() {
    sf::Vector2f direction;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        direction.x = -1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        direction.x = 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        direction.y = 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        direction.y = -1;
    }

    if (direction.x != 0.f && direction.y != 0.f) {
        direction /= std::sqrt(2.f);
    }

    _player.move(direction);

    direction = {};
}
