#pragma once

#include "SFML/Graphics.hpp"
#include "map"

class AssetManager {
public:
    AssetManager() = default;

    ~AssetManager() = default;

    void loadTexture(const std::string& textureName, const std::string& fileName);

    sf::Texture &getTexture(const std::string& textureName);

private:
    std::map<std::string, sf::Texture> _loadedTextures;
};