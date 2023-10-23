#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../../config.h"

class SoundManager {
public:
    void playBackgroundTheme();

private:
    sf::Music backgroundmusic;
};