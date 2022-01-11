#pragma once

#include "color.h"
#include "rect.h"
#include "renderer.h"
#include "utils.h"

class Entity : public Rect
{
public:
    float z;

    Entity() = default;
};

class EntityPool
{
public:
    static const int kMinSize = 50;
    static const int kMaxSize = 300;
    static constexpr const float kVel = -10;

    EntityPool(int entity_count, int max_x, int max_y);
    ~EntityPool() { delete[] entities_; }
    EntityPool() {};

    void UpdateAndDraw(Renderer &renderer);

private:
    int entity_count_;
    Entity *entities_ = nullptr;
    int window_w_;
    int window_h_;

    void ResetEntity(Entity &e);
};
