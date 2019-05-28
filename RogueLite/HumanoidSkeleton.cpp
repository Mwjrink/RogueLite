#include "HumanoidSkeleton.h"

#include "World.h"

#include <iostream>

#define PI 3.14159265359

namespace proc_anim
{
    void set_unit_velocity_up(int _, int __) { world::skeleton.heart.velocity.y++; }
    void set_unit_velocity_down(int _, int __) { world::skeleton.heart.velocity.y--; }
    void set_unit_velocity_left(int _, int __) { world::skeleton.heart.velocity.x--; }
    void set_unit_velocity_right(int _, int __) { world::skeleton.heart.velocity.x++; }
    void stop_velocity_up(int _, int __) { world::skeleton.heart.velocity.y--; }
    void stop_velocity_down(int _, int __) { world::skeleton.heart.velocity.y++; }
    void stop_velocity_left(int _, int __) { world::skeleton.heart.velocity.x++; }
    void stop_velocity_right(int _, int __) { world::skeleton.heart.velocity.x--; }

    void reset(int _, int __)
    {
        auto s = &world::skeleton;

        s->head.position = s->heart.position + glm::vec3(0.0f, 0.0f, s->neck_length);
        auto left        = glm::vec3(s->facing_direction.y, -s->facing_direction.x, 0.0f);

        // Make torso/shoulders to new direction, instead of instant pivoting
        auto shoulder_direction    = left * s->shoulder_width * 0.5f;
        s->left_shoulder.position  = s->heart.position + shoulder_direction;
        s->right_shoulder.position = s->heart.position - shoulder_direction;

        s->pelvis.position = s->heart.position - glm::vec3(0.0f, 0.0f, s->torso_length);

        s->left_foot.position = s->pelvis.position + glm::normalize(left + glm::vec3(0.0f, 0.0f, -2)) * s->leg_length;

        s->right_foot.position = s->pelvis.position + glm::normalize(-left + glm::vec3(0.0f, 0.0f, -2)) * s->leg_length;
    }

    const glm::vec3 red = glm::vec3(1.0f, 0.0f, 0.0f);
    const glm::vec3 blu = glm::vec3(0.0f, 0.0f, 1.0f);
    const glm::vec3 gre = glm::vec3(0.0f, 1.0f, 0.0f);

    const float looking_angle_y_mult = std::sin(PI / 4);

    const float rootThreeOverTwo = std::sqrt(3) / 2;

    float heartToFootZ;

    HumanoidSkeleton::HumanoidSkeleton()
    {
        r.tile_sheet = Create_TileSheet(gltexture::AllocateTextureForLoading("Resources/node.png"), glm::ivec2(1, 1));
        // r.position   = glm::vec2(1720.0f, 980.0f);
        r.position           = glm::vec2(0.0f, 0.0f);
        r.size               = glm::vec2(16.0f, 16.0f);
        r.scale              = 1.0f;
        r.current_tile_index = 0;

        speed          = 100.0f;
        arm_length     = 40.0f;
        leg_length     = 60.0f;
        neck_length    = 20.0f;
        shoulder_width = 40.0f;
        torso_length   = 50.0f;

        calf_length  = leg_length * 0.5f;
        thigh_length = calf_length;

        facing_direction = glm::vec3(0.0f, -1.0f, 0.0f);

        heart = Node(500.0f, 250.0f, 0.0f, 0.0f);

        head = Node(500.0f, 250.0f, neck_length, 2.0f);

        left_shoulder  = Node(480.0f, 250.0f, 0.0f, 1.0f);
        right_shoulder = Node(520.0f, 250.0f, 0.0f, 1.0f);

        // left_elbow  = Node(425.0f, 225.0f, 0.0f, 0.5f);
        // right_elbow = Node(575.0f, 225.0f, 0.0f, 0.5f);

        left_hand  = Node(425.0f, 250.0f, -arm_length, 0.75f);
        right_hand = Node(575.0f, 250.0f, -arm_length, 0.75f);

        pelvis = Node(500.0f, 250.0f, -torso_length, 1.0f);

        // left_knee  = Node(475.0f, 187.5f, 0.0f, 0.5f);
        // right_knee = Node(525.0f, 187.5f, 0.0f, 0.5f);

        heartToFootZ = -torso_length - leg_length * rootThreeOverTwo;

        left_foot  = Node(480.0f, 250.0f, heartToFootZ, 0.75f);
        right_foot = Node(520.0f, 250.0f, heartToFootZ, 0.75f);

        left_planted = false;
        // step_destination = left_foot.position;
        // velocity_at_step = glm::vec3(0.0f);
        // step_travel      = 0;
        // max_step_travel  = std::sin(PI / 6) * leg_length * speed * 0.02;

        input::copy_add_event(GLFW_KEY_W, GLFW_PRESS, &input::delegate_type::create<&proc_anim::set_unit_velocity_up>());
        input::copy_add_event(GLFW_KEY_A, GLFW_PRESS, &input::delegate_type::create<&proc_anim::set_unit_velocity_left>());
        input::copy_add_event(GLFW_KEY_S, GLFW_PRESS, &input::delegate_type::create<&proc_anim::set_unit_velocity_down>());
        input::copy_add_event(GLFW_KEY_D, GLFW_PRESS, &input::delegate_type::create<&proc_anim::set_unit_velocity_right>());

        input::copy_add_event(GLFW_KEY_SPACE, GLFW_PRESS, &input::delegate_type::create<&proc_anim::reset>());

        input::copy_add_event(GLFW_KEY_W, GLFW_RELEASE, &input::delegate_type::create<&proc_anim::stop_velocity_up>());
        input::copy_add_event(GLFW_KEY_A, GLFW_RELEASE, &input::delegate_type::create<&proc_anim::stop_velocity_left>());
        input::copy_add_event(GLFW_KEY_S, GLFW_RELEASE, &input::delegate_type::create<&proc_anim::stop_velocity_down>());
        input::copy_add_event(GLFW_KEY_D, GLFW_RELEASE, &input::delegate_type::create<&proc_anim::stop_velocity_right>());
    }

    void move(HumanoidSkeleton& s, float dt, glm::vec3 curs_pos)
    {
        s.facing_direction =
            glm::normalize(s.heart.position - glm::vec3(curs_pos.x, curs_pos.y / looking_angle_y_mult, 0.0f));

        if (s.heart.velocity.x != 0.0f || s.heart.velocity.y != 0.0f)
        {
            s.moving_direction = glm::normalize(s.heart.velocity);
            s.heart.position += s.moving_direction * s.speed * dt;
        }

        s.head.position = s.heart.position + glm::vec3(0.0f, 0.0f, s.neck_length);
        auto left       = glm::vec3(s.facing_direction.y, -s.facing_direction.x, 0.0f);

        // Make torso/shoulders to new direction, instead of instant pivoting
        auto shoulder_direction   = left * s.shoulder_width * 0.5f;
        s.left_shoulder.position  = s.heart.position + shoulder_direction;
        s.right_shoulder.position = s.heart.position - shoulder_direction;

        s.pelvis.position = s.heart.position - glm::vec3(0.0f, 0.0f, s.torso_length);

        // FEET
        // Foot.position.z proportional to planted foots distance from the pelvis?
        // ie. sin(glm::distance((s.foot.position, s.pelvis.position) - rootThreeOverTwo ) / s.leg_length); ??
        {
            if (s.left_planted)
            {
                if (glm::distance(s.left_foot.position, s.pelvis.position) > s.leg_length)
                {
                    s.left_planted = false;
                    // std::cout << "right: " << s.right_foot.position.z - heartToFootZ << std::endl;
                    s.right_foot.position.z = heartToFootZ;
                }
                else
                {
                    // TODO, why 3? and maybe make it a dynamically changing number?
                    auto delta = s.speed * dt * 3.0f;

                    auto dest = s.moving_direction * s.leg_length * 0.5f + s.pelvis.position -
                                glm::vec3(0.0f, 0.0f, s.leg_length * rootThreeOverTwo) - shoulder_direction;
                    s.right_foot.position += glm::normalize(dest - s.right_foot.position) * delta;

                    s.right_foot.position.z =
                        -s.torso_length - s.leg_length * rootThreeOverTwo +
                        std::cos(PI * glm::distance(glm::vec2(s.left_foot.position), glm::vec2(s.left_shoulder.position)) /
                                 s.leg_length) *
                            0.5f * s.leg_length;

                    // std::cout << "right: "
                    //          << glm::distance(glm::vec2(s.right_foot.position), glm::vec2(s.right_shoulder.position)) /
                    //                 s.leg_length
                    //          << std::endl;
                }
            }
            else
            {
                if (glm::distance(s.right_foot.position, s.pelvis.position) > s.leg_length)
                {
                    s.left_planted = true;
                    // std::cout << "left: " << s.left_foot.position.z - heartToFootZ << std::endl;
                    s.left_foot.position.z = heartToFootZ;
                }
                else
                {
                    // TODO, why 3? and maybe make it a dynamically changing number?
                    auto delta = s.speed * dt * 3.0f;

                    auto dest = s.moving_direction * s.leg_length * 0.5f + s.pelvis.position -
                                glm::vec3(0.0f, 0.0f, s.leg_length * rootThreeOverTwo) + shoulder_direction;
                    s.left_foot.position += glm::normalize(dest - s.left_foot.position) * delta;

                    s.left_foot.position.z =
                        -s.torso_length - s.leg_length * rootThreeOverTwo +
                        std::cos(PI * glm::distance(glm::vec2(s.right_foot.position), glm::vec2(s.right_shoulder.position)) /
                                 s.leg_length) *
                            0.5f * s.leg_length;

                    // std::cout << "left: "
                    //          << glm::distance(glm::vec2(s.left_foot.position), glm::vec2(s.left_shoulder.position)) /
                    //                 s.leg_length
                    //          << std::endl;
                }
            }

            // s.left_foot.position  = s.pelvis.position + shoulder_direction - glm::vec3(0.0f, 0.0f, s.leg_length);
            // s.right_foot.position = s.pelvis.position - shoulder_direction - glm::vec3(0.0f, 0.0f, s.leg_length);

            // KNEES
            {
                // if (s.left_planted)
                {
                    auto  c = glm::distance(s.pelvis.position, s.right_foot.position);
                    float theta =
                        std::acos((std::pow(s.thigh_length, 2.0f) - std::pow(c, 2.0f) - std::pow(s.calf_length, 2.0f)) /
                                  (s.calf_length * c * (-2.0f)));

                    if (isnan(theta))
                    {
                        theta = 0;
                    }

                    float angle =
                        std::acos(glm::dot(s.right_foot.position - s.pelvis.position, s.facing_direction) / c) - theta;

                    auto v_offset = s.facing_direction * s.calf_length * std::cos(angle);
                    s.right_knee.position =
                        glm::vec3(s.right_foot.position.x - v_offset.x, s.right_foot.position.y - v_offset.y,
                                  s.right_foot.position.z + s.calf_length * std::sin(angle));

                    std::cout << "theta: " << theta << ", angle: " << angle << std::endl;

                    /*if (angle == 0)
                    {
                        s.right_knee.position = glm::vec3(s.right_foot.position.x + c*0.5f, s.right_foot.position.y + c*0.5f,
                    s.right_foot.position.z);
                    }*/
                }
                // else
                {
                    auto  c = glm::distance(s.pelvis.position, s.left_foot.position);
                    float theta =
                        std::acos((std::pow(s.thigh_length, 2.0f) - std::pow(c, 2.0f) - std::pow(s.calf_length, 2.0f)) /
                                  (s.calf_length * c * (-2.0f)));
                    float angle =
                        std::acos(glm::dot(s.left_foot.position - s.pelvis.position, s.facing_direction) / c) - theta;

                    auto v_offset = s.facing_direction * s.calf_length * std::cos(angle);
                    s.left_knee.position =
                        glm::vec3(s.left_foot.position.x - v_offset.x, s.left_foot.position.y - v_offset.y,
                                  s.left_foot.position.z + s.calf_length * std::sin(angle));

                    std::cout << "theta: " << theta << ", angle: " << angle << std::endl;

                    /*if (angle == 0)
                    {
                        s.left_knee.position = glm::vec3(s.left_foot.position.x + c * 0.5f,
                                                          s.left_foot.position.y + c * 0.5f, s.left_foot.position.z);
                    }*/
                }
            }
        }

        // HAND
        {
            auto arm_z = glm::vec3(0.0f, 0.0f, s.arm_length * 0.5f);
            // ELBOWS
            //{
            //    s.left_elbow.position  = s.left_shoulder.position + shoulder_direction - arm_z;
            //    s.right_elbow.position = s.right_shoulder.position - shoulder_direction - arm_z;
            //}

            // TEMP
            s.left_hand.position  = s.left_shoulder.position + shoulder_direction - arm_z - arm_z;
            s.right_hand.position = s.right_shoulder.position - shoulder_direction - arm_z - arm_z;
        }
    }

    glm::vec2 transform_3d_to_render_coords(glm::vec3& coords, float sin_of_viewing_angle, float cos_of_viewing_angle)
    {
        return glm::vec2(coords.x, coords.y * sin_of_viewing_angle + coords.z * cos_of_viewing_angle);
    }

    void render(HumanoidSkeleton& s)
    {
        // graphics::DrawLine(s.head.position.x, s.head.position.y, s.pelvis.position.x, s.pelvis.position.y, 4.0f);

        // graphics::DrawLine(s.left_shoulder.position.x, s.left_shoulder.position.y, s.right_shoulder.position.x,
        //                   s.right_shoulder.position.y, 4.0f);

        // graphics::DrawLine(s.left_shoulder.position.x, s.left_shoulder.position.y, s.left_elbow.position.x,
        //                   s.left_elbow.position.y, 4.0f);
        // graphics::DrawLine(s.right_shoulder.position.x, s.right_shoulder.position.y, s.right_elbow.position.x,
        //                   s.right_elbow.position.y, 4.0f);

        // graphics::DrawLine(s.left_elbow.position.x, s.left_elbow.position.y, s.left_hand.position.x,
        // s.left_hand.position.y,
        //                   4.0f);
        // graphics::DrawLine(s.right_elbow.position.x, s.right_elbow.position.y, s.right_hand.position.x,
        //                   s.right_hand.position.y, 4.0f);

        // graphics::DrawLine(s.pelvis.position.x, s.pelvis.position.y, s.left_knee.position.x,
        // s.left_knee.position.y, 4.0f); graphics::DrawLine(s.pelvis.position.x, s.pelvis.position.y,
        // s.right_knee.position.x, s.right_knee.position.y, 4.0f);

        // graphics::DrawLine(s.left_knee.position.x, s.left_knee.position.y, s.left_foot.position.x, s.left_foot.position.y,
        //                   4.0f);
        // graphics::DrawLine(s.right_knee.position.x, s.right_knee.position.y, s.right_foot.position.x,
        //                   s.right_foot.position.y, 4.0f);

        s.r.position = transform_3d_to_render_coords(s.left_foot.position, looking_angle_y_mult, looking_angle_y_mult);
        s.r.scale    = s.left_foot.radius;
        s.r.color    = red;
        graphics::DrawRenderable(s.r, graphics::shaderProgram);

        s.r.position = transform_3d_to_render_coords(s.right_foot.position, looking_angle_y_mult, looking_angle_y_mult);
        s.r.scale    = s.right_foot.radius;
        s.r.color    = red;
        graphics::DrawRenderable(s.r, graphics::shaderProgram);

        s.r.position = transform_3d_to_render_coords(s.left_knee.position, looking_angle_y_mult, looking_angle_y_mult);
        s.r.scale    = s.left_knee.radius;
        s.r.color    = blu;
        graphics::DrawRenderable(s.r, graphics::shaderProgram);

        s.r.position = transform_3d_to_render_coords(s.right_knee.position, looking_angle_y_mult, looking_angle_y_mult);
        s.r.scale    = s.right_knee.radius;
        s.r.color    = blu;
        graphics::DrawRenderable(s.r, graphics::shaderProgram);

        s.r.position = transform_3d_to_render_coords(s.pelvis.position, looking_angle_y_mult, looking_angle_y_mult);
        s.r.scale    = s.pelvis.radius;
        s.r.color    = gre;
        graphics::DrawRenderable(s.r, graphics::shaderProgram);

        s.r.position = transform_3d_to_render_coords(s.left_hand.position, looking_angle_y_mult, looking_angle_y_mult);
        s.r.scale    = s.left_hand.radius;
        s.r.color    = red;
        graphics::DrawRenderable(s.r, graphics::shaderProgram);

        s.r.position = transform_3d_to_render_coords(s.right_hand.position, looking_angle_y_mult, looking_angle_y_mult);
        s.r.scale    = s.right_hand.radius;
        s.r.color    = red;
        graphics::DrawRenderable(s.r, graphics::shaderProgram);

        // s.r.position = transform_3d_to_render_coords(s.left_elbow.position, looking_angle_y_mult, looking_angle_y_mult);
        // s.r.scale    = s.left_elbow.radius;
        // s.r.color    = blu;
        // graphics::DrawRenderable(s.r, graphics::shaderProgram);

        // s.r.position = transform_3d_to_render_coords(s.right_elbow.position, looking_angle_y_mult, looking_angle_y_mult);
        // s.r.scale    = s.right_elbow.radius;
        // s.r.color    = blu;
        // graphics::DrawRenderable(s.r, graphics::shaderProgram);

        s.r.position = transform_3d_to_render_coords(s.left_shoulder.position, looking_angle_y_mult, looking_angle_y_mult);
        s.r.scale    = s.left_shoulder.radius;
        s.r.color    = gre;
        graphics::DrawRenderable(s.r, graphics::shaderProgram);

        s.r.position = transform_3d_to_render_coords(s.right_shoulder.position, looking_angle_y_mult, looking_angle_y_mult);
        s.r.scale    = s.right_shoulder.radius;
        s.r.color    = gre;
        graphics::DrawRenderable(s.r, graphics::shaderProgram);

        s.r.position = transform_3d_to_render_coords(s.head.position, looking_angle_y_mult, looking_angle_y_mult);
        s.r.scale    = s.head.radius;
        s.r.color    = red;
        graphics::DrawRenderable(s.r, graphics::shaderProgram);

        // FOR DEBUGGING
        // s.r.position = transform_3d_to_render_coords(s.heart.position, looking_angle_y_mult, looking_angle_y_mult);
        // s.r.scale    = 1.0;
        // s.r.color    = glm::vec3(1.0f, 1.0f, 1.0f);
        // graphics::DrawRenderable(s.r, graphics::shaderProgram);
    }

}  // namespace proc_anim
