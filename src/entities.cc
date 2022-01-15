#include "entities.h"
#include "utils.h"
#include <SDL2/SDL.h>

EntityPool::EntityPool(int entity_count, int window_w, int window_h)
    : entity_count_(entity_count), entities_(new Entity[entity_count]),
      window_w_(window_w), window_h_(window_h)
{
    for (int i = 0; i < entity_count; i++)
    {
        ResetEntity(entities_[i]);
        entities_[i].y += randint(window_h * 1, window_h * 2);
    }
}

void EntityPool::UpdateAndDraw(Renderer &renderer)
{
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_ADD);
    for (int i = 0; i < entity_count_; i++)
    {
        Entity &e = entities_[i];

        e.y += kVel * e.z;

        if (e.bottom() < 0)
        {
            ResetEntity(e);
        }
        renderer.DrawFillRect(e, Color(100 * e.z, 255));
    }
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
}

void EntityPool::ResetEntity(Entity &e)
{
    e.x = randint(-e.w / 2, window_w_ - e.w / 2);
    e.y = window_h_;
    e.w = randint(kMinSize, kMaxSize);
    e.h = randint(kMinSize, kMaxSize);
    e.z = randint(1, 10) * 0.1f;
}
