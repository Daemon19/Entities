#include "color.h"
#include <string>

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

Color::operator std::string() const
{
    return "Color(" + std::to_string(r) + ", " + std::to_string(g) + ", " +
           std::to_string(b) + ", " + std::to_string(a) + ", " + ")";
}