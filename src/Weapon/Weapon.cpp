#include "Weapon.h"

void Weapon::setTexture(const sf::Texture &texture) {
    _texture = texture;

    _sprite.setTexture(texture);

    _sprite.setScale(0.3f, 0.3f);

    _sprite.setTextureRect(sf::IntRect(67, 76, 137, 47));
}

sf::Sprite &Weapon::getSprite() {
    return _sprite;
}

void Weapon::setPosition(const sf::Vector2f &position) {
    _sprite.setPosition(position);
}

void Weapon::update() {
    _sprite.rotate(1);
}
