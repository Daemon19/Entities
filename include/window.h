#pragma once

#include <SDL2/SDL.h>
#include <string>

class Window
{
public:
    Window(const Window &) = delete;
    Window() = default;
    ~Window();

    bool Init(const std::string &title, int w, int h, Uint32 flags);
    bool Init(const std::string &title, int w, int h);

    operator SDL_Window *() { return window_; }

    int w() const { return w_; }
    int h() const { return h_; }

private:
    SDL_Window *window_ = nullptr;
    std::string title_;
    int w_, h_;
};
