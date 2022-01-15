#include "utils.h"
#include <SDL2/SDL.h>
#include <iostream>

void LogSdlError(const std::string &message)
{
    std::cerr << "[SDL ERROR] " << message << " : " << SDL_GetError() << std::endl;
}

void LogError(const std::string &message)
{
    std::cerr << "[ERROR] " << message << std::endl;
}