#pragma once

#include <glad/glad.h>

#include <string>
#include <unordered_map>
#include <vector>

#include "ShelfPack.h"

namespace gltexture
{
    struct GLTexture
    {
        unsigned int id;
        unsigned int width;
        unsigned int height;
        unsigned int atlas_x, atlas_y;
        unsigned int atlas_width, atlas_height;
    };

    extern int    current_max_id;
    extern GLuint atlas_texture_id;

    GLTexture* AllocateTextureForLoading(std::string texture_path);

    unsigned int GenerateAtlas(bool flip_vertically);

    void ClearCurrentAtlas();

    extern std::vector<std::string> paths;
    extern std::vector<mapbox::Bin> bins;
    extern std::vector<GLTexture*>  textures;
}  // namespace gltexture
