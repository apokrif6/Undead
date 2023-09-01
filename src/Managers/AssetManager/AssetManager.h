#pragma once

#include "SFML/Graphics.hpp"
#include "map"

class AssetManager {
public:
    AssetManager() = default;

    ~AssetManager() = default;

    void LoadTexture(const std::string& texture_name, const std::string& file_name);

    sf::Texture &GetTexture(const std::string& texture_name);

private:
    std::map<std::string, sf::Texture> loaded_textures;
};