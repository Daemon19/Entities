#include "renderer.h"
#include <SDL2/SDL.h>
#include "utils.h"

Renderer::~Renderer()
{
    if (renderer_ != nullptr)
        SDL_DestroyRenderer(renderer_);
}

bool Renderer::Init(Window &window)
{
    renderer_ = SDL_CreateRenderer(window, -1,
                                   SDL_RENDERER_ACCELERATED |
                                       SDL_RENDERER_PRESENTVSYNC);
    if (renderer_ == nullptr)
    {
        LogSdlError("Gagal membuat renderer");
        return false;
    }
    return true;
}

bool Renderer::SetDrawColor(const SDL_Color &color)
{
    return SDL_SetRenderDrawColor(renderer_, color.r, color.g,
                                  color.b, color.a) == 0;
}

bool Renderer::Fill(const SDL_Color &color)
{
    return SetDrawColor(color) && SDL_RenderClear(renderer_) == 0;
}

bool Renderer::DrawFillRect(const SDL_Rect &rect, const SDL_Color &color)
{
    return SetDrawColor(color) && SDL_RenderFillRect(renderer_, &rect) == 0;
}
