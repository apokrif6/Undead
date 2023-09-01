#include "AssetManager.h"
#include <iostream>
#include <fstream>

void AssetManager::LoadTexture(const std::string &texture_name, const std::string &file_name) {
    sf::Texture texture;

    if (!texture.loadFromFile(file_name)) return;

    loaded_textures[texture_name] = texture;
}

sf::Texture &AssetManager::GetTexture(const std::string &texture_name) {
    try {
        return loaded_textures.at(texture_name);
    } catch (const std::out_of_range &exception) {
        //TODO
        //create logger
        std::ofstream file("log.txt");
        file << "Texture " + texture_name + "wasn't loaded" << std::endl;
    }
}
