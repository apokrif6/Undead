#include "InputManager.h"

void InputManager::HandleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        mr_player.MoveLeft();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        mr_player.MoveRight();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        mr_player.MoveDown();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        mr_player.MoveUp();
    }
}
