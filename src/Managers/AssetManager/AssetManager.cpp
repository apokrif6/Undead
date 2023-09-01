#include "AssetManager.h"
#include <iostream>
#include <fstream>

void AssetManager::LoadTexture(const std::string &textureName, const std::string &fileName) {
    sf::Texture texture;

    if (!texture.loadFromFile(fileName)) return;

    m_loadedTextures[textureName] = texture;
}

sf::Texture &AssetManager::GetTexture(const std::string &textureName) {
    try {
        return m_loadedTextures.at(textureName);
    } catch (const std::out_of_range &exception) {
        //TODO
        //create logger
        std::ofstream file("log.txt");
        file << "Texture " + textureName + "wasn't loaded" << std::endl;
    }
}
