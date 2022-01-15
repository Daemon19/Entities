#pragma once

#include <SDL2/SDL.h>
#include <string>

class Color
{
public:
    Uint8 r, g, b, a;

    Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    Color(Uint8 r, Uint8 g, Uint8 b) { *this = Color(r, g, b, 255); }
    Color(Uint8 rgb, Uint8 a) { *this = Color(rgb, rgb, rgb, a); }
    Color(Uint8 rgb) { *this = Color(rgb, 255); }
    Color() { *this = Color(0, 0, 0); }

    operator SDL_Color() const { return SDL_Color{r, g, b, a}; }
    operator std::string() const;
};
