#include <SDL2/SDL.h>
#include <iostream>

#include "entities.h"
#include "renderer.h"
#include "utils.h"
#include "window.h"

class Game
{
public:
    Game(int entity_count)
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            LogSdlError("Gagal menginisialisasi SDL");
            exit(-1);
        }

        window_.Init("Hanya sebuah test", 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
        renderer_.Init(window_);
        entities_ = new EntityPool(entity_count, window_.w(), window_.h());

        Run();
        delete entities_;
        SDL_Quit();
    }

private:
    bool running_ = true;
    Window window_;
    Renderer renderer_;
    EntityPool *entities_ = nullptr;

    void Run()
    {
        while (running_)
        {
            SDL_Event e;
            while (SDL_PollEvent(&e))
            {
                if (e.type == SDL_QUIT)
                    running_ = false;
                if (e.type == SDL_KEYDOWN)
                {
                    if (e.key.keysym.sym == SDLK_ESCAPE)
                        running_ = false;
                }
            }

            renderer_.Fill(Color(20, 20, 30, 255));
            entities_->UpdateAndDraw(renderer_);
            renderer_.UpdateDisplay();
        }
    }
};

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        std::cerr << "penggunaan: ./Entities.exe jumlah_entity" << std::endl;
        return -1;
    }
    if (argc == 2)
        Game game(atoi(argv[1]));
    else
        Game game(80);
    return 0;
}
