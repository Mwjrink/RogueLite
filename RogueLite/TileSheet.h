#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "GLTexture.h"

class TileSheet
{
  public:
    gltexture::GLTexture* texture;
    glm::ivec2            sprite_dimensions;
    unsigned int          sprite_width;
    unsigned int          sprite_height;
};

TileSheet Create_TileSheet(gltexture::GLTexture* texture, const glm::ivec2& tileDims);

glm::vec4 getUVs(TileSheet sheet, int index);
