#pragma once

#include <llvm/ADT/SmallVector.h>
#include <glm/glm.hpp>

#include "Graphics.h"
//#include "TileSheet.h"
#include "Renderable.h"
#include "World.h"

//#define h 1
//#define p 2
//#define m 4
//#define d 8
//#define s 16
//#define g 32
//#define f 64
//
//// 65535
// const short humanoid[7 * 6] = {
//    0, 0, 0, h, 0, 0, 0,  //.........................................................................
//    0, 0, p, m, p, 0, 0,  //.........................................................................
//    0, d, 0, 0, 0, d, 0,  //.........................................................................
//    g, 0, 0, s, 0, 0, g,  //.........................................................................
//    0, 0, d, 0, d, 0, 0,  //.........................................................................
//    0, f, 0, 0, 0, f, 0   //.........................................................................
//}

namespace proc_anim
{
    class Skeleton
    {
      public:
        class Node
        {
          public:
            glm::vec2 position;
            glm::vec2 velocity;
            float     radius;

            Node() = default;

            Node(float x, float y, float w) : position(x, y), velocity(0.0f, 0.0f), radius(w) {}
            // connections to other nodes and what kind of connection they are
        };

        // temp shit
        Renderable r;
        float      dist;
        float      speed;

        // temp shit

        llvm::SmallVector<Node, 16> nodes;
        unsigned short              headIndex = 0;

        Skeleton();
    };

    void move(glm::vec3 direction, float dt);

    void render(Skeleton& s);

    Skeleton::Node get_head(Skeleton& s);

    void set_unit_velocity_up(int _, int __) { world::skeleton.get_head().velocity.y++; }
    void set_unit_velocity_down(int _, int __) { world::skeleton.get_head().velocity.y--; }
    void set_unit_velocity_left(int _, int __) { world::skeleton.get_head().x--; }
    void set_unit_velocity_right(int _, int __) { world::skeleton.get_head().x++; }
    void stop_velocity_up(int _, int __) { world::skeleton.get_head().y--; }
    void stop_velocity_down(int _, int __) { world::skeleton.get_head().y++; }
    void stop_velocity_left(int _, int __) { world::skeleton.get_head().x++; }
    void stop_velocity_right(int _, int __) { world::skeleton.get_head().x--; }
}  // namespace proc_anim
