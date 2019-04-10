#pragma once

#include <vector>

#include "Graphics.h"
#include "TileSheet.h"

class TileSheet;

namespace level
{
    class Level
    {
      public:
        TileSheet*    tile_sheet;
        unsigned int* map;  // int[,] or int[][]
        unsigned int  width, height;
    };

	void Init(Level* target);
    void RenderLevel(Level* render_target);

    extern unsigned int         base_map_width;
    extern unsigned int			base_map_height;
    
    extern unsigned int* base_map;

    // 0 = water;
    // 1 = lava;
    // 2 = grass;
    // 3 = earth / stone;

    extern unsigned int* collision_map;
}  // namespace level
