#include "AssetManager.h"
#include <iostream>
#include <fstream>

void AssetManager::loadTexture(const std::string &textureName, const std::string &fileName) {
    sf::Texture texture;

    if (!texture.loadFromFile(fileName)) return;

    _loadedTextures[textureName] = texture;
}

sf::Texture &AssetManager::getTexture(const std::string &textureName) {
    try {
        return _loadedTextures.at(textureName);
    } catch (const std::out_of_range &exception) {
        //TODO
        //create logger
        std::ofstream file("log.txt");
        file << "Texture " + textureName + "wasn't loaded" << std::endl;
    }
}
