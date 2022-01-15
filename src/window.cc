#include "window.h"
#include "utils.h"
#include <SDL2/SDL.h>
#include <string>

Window::~Window()
{
    if (window_ != nullptr)
        SDL_DestroyWindow(window_);
}

bool Window::Init(const std::string &title, int w, int h, Uint32 flags)
{
    title_ = title;

    window_ = SDL_CreateWindow(title_.c_str(),
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               w, h, flags);
    if (window_ == nullptr)
    {
        LogSdlError("Gagal membuat _");
        return false;
    }
    // w = w_ akan sia-sia jika flag fullscreen digunakan
    SDL_GetWindowSize(window_, &w_, &h_);
    return true;
}

bool Window::Init(const std::string &title, int w, int h)
{
    return Init(title, w, h, 0);
}