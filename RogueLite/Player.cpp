#include "Player.h"
#include <iostream>
#include "World.h"

namespace player
{
    void player_init(Player& p)
    {
        p.tile_sheet = Create_TileSheet(gltexture::AllocateTextureForLoading("Resources/NPC.png"), glm::ivec2(9, 8));
        // r.position   = glm::vec2(1720.0f, 980.0f);
        p.position           = glm::vec2(1250.0f, 500.0f);
        p.velocity           = glm::vec2(0.0f, 0.0f);
        p.size               = glm::vec2(48.0f, 48.0f);
        p.scale              = 1.0f;
        p.current_tile_index = 0;
        p.speed              = 192.0f;

        float timing                                                    = 0.3f;
        p.current_frame                                                 = new Renderable::aframe(0, timing);
        p.current_frame->next_frame                                     = new Renderable::aframe(1, timing);
        p.current_frame->next_frame->next_frame                         = new Renderable::aframe(2, timing);
        p.current_frame->next_frame->next_frame->next_frame             = new Renderable::aframe(1, timing);
        p.current_frame->next_frame->next_frame->next_frame->next_frame = p.current_frame;

        // TODO: ABOLISH THIS SYSTEM IN FAVOUR OF POLLING :'(
        // input::delegate_type dLambda = [](int key, int action) {
        //    switch (action)
        //    {
        //        case GLFW_PRESS:
        //            switch (key)
        //            {
        //                case GLFW_KEY_W: set_unit_velocity_up(world::player); break;
        //                case GLFW_KEY_A: set_unit_velocity_left(world::player); break;
        //                case GLFW_KEY_S: set_unit_velocity_down(world::player); break;
        //                case GLFW_KEY_D: set_unit_velocity_right(world::player); break;
        //            };
        //            break;
        //        case GLFW_RELEASE:
        //            switch (key)
        //            {
        //                case GLFW_KEY_W: stop_velocity_up(world::player); break;
        //                case GLFW_KEY_A: stop_velocity_left(world::player); break;
        //                case GLFW_KEY_S: stop_velocity_down(world::player); break;
        //                case GLFW_KEY_D: stop_velocity_right(world::player); break;
        //            };
        //            break;
        //    }
        //};

        input::copy_add_event(GLFW_KEY_W, GLFW_PRESS, &input::delegate_type::create<&player::set_unit_velocity_up>());
        input::copy_add_event(GLFW_KEY_A, GLFW_PRESS, &input::delegate_type::create<&player::set_unit_velocity_left>());
        input::copy_add_event(GLFW_KEY_S, GLFW_PRESS, &input::delegate_type::create<&player::set_unit_velocity_down>());
        input::copy_add_event(GLFW_KEY_D, GLFW_PRESS, &input::delegate_type::create<&player::set_unit_velocity_right>());
        input::copy_add_event(GLFW_KEY_W, GLFW_RELEASE, &input::delegate_type::create<&player::stop_velocity_up>());
        input::copy_add_event(GLFW_KEY_A, GLFW_RELEASE, &input::delegate_type::create<&player::stop_velocity_left>());
        input::copy_add_event(GLFW_KEY_S, GLFW_RELEASE, &input::delegate_type::create<&player::stop_velocity_down>());
        input::copy_add_event(GLFW_KEY_D, GLFW_RELEASE, &input::delegate_type::create<&player::stop_velocity_right>());
    }

    void move(Player& p, float dt)
    {
        if (p.velocity.x != 0.0f || p.velocity.y != 0.0f) p.position += glm::normalize(p.velocity) * p.speed * dt;
    }

    /*
    void set_unit_velocity_up(int _, int __) { world::player.velocity.y = 1; }
    void set_unit_velocity_down(int _, int __) { world::player.velocity.y = -1; }
    void set_unit_velocity_left(int _, int __) { world::player.velocity.x = -1; }
    void set_unit_velocity_right(int _, int __) { world::player.velocity.x = 1; }
    void stop_velocity_up(int _, int __) { world::player.velocity.y = std::min(world::player.velocity.y, 0.0f); }
    void stop_velocity_down(int _, int __) { world::player.velocity.y = std::max(world::player.velocity.y, 0.0f); }
    void stop_velocity_left(int _, int __) { world::player.velocity.x = std::max(world::player.velocity.x, 0.0f); }
    void stop_velocity_right(int _, int __) { world::player.velocity.x = std::min(world::player.velocity.x, 0.0f); }
    */

    void set_unit_velocity_up(int _, int __) { world::player.velocity.y++; }
    void set_unit_velocity_down(int _, int __) { world::player.velocity.y--; }
    void set_unit_velocity_left(int _, int __) { world::player.velocity.x--; }
    void set_unit_velocity_right(int _, int __) { world::player.velocity.x++; }
    void stop_velocity_up(int _, int __) { world::player.velocity.y--; }
    void stop_velocity_down(int _, int __) { world::player.velocity.y++; }
    void stop_velocity_left(int _, int __) { world::player.velocity.x++; }
    void stop_velocity_right(int _, int __) { world::player.velocity.x--; }
}  // namespace player
