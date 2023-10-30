#include "SoundManager.h"

void SoundManager::playBackgroundTheme() {
    if (!backgroundmusic.openFromFile(BACKGROUND_THEME_FILE_NAME))
        return;

    backgroundmusic.setVolume(15);
    backgroundmusic.play();
}