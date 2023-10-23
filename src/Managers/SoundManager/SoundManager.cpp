#include "SoundManager.h"

void SoundManager::playBackgroundTheme() {
    if (!backgroundmusic.openFromFile("resources/audio/background_theme.wav"))
        return;

    backgroundmusic.setVolume(15);
    backgroundmusic.play();
}