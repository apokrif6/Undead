#include "InputManager.h"

void InputManager::HandleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        r_shape.move(sf::Vector2f(-0.5f, 0.f));
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        r_shape.move(sf::Vector2f(0.5f, 0.f));
    }
}
