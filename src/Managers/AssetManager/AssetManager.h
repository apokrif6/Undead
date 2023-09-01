#pragma once

#include "SFML/Graphics.hpp"
#include "map"

class AssetManager {
public:
    AssetManager() = default;

    ~AssetManager() = default;

    void LoadTexture(const std::string& textureName, const std::string& fileName);

    sf::Texture &GetTexture(const std::string& textureName);

private:
    std::map<std::string, sf::Texture> m_loadedTextures;
};