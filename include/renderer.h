#pragma once

#include "utils.h"
#include "window.h"
#include <SDL.h>

class Renderer
{
public:
    Renderer(const Renderer &) = delete;
    Renderer() = default;
    ~Renderer();

    bool Init(Window &window);
    bool SetDrawColor(const SDL_Color &color);
    bool Fill(const SDL_Color &color);
    bool DrawFillRect(const SDL_Rect &rect, const SDL_Color &color);
    void UpdateDisplay() { SDL_RenderPresent(renderer_); }

    operator SDL_Renderer *() { return renderer_; }

private:
    SDL_Renderer *renderer_ = nullptr;
};
