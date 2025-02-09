#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include "game.h"

using namespace std;

int main(int argc, char* argv[])
{
    Graphics graphics;
    graphics.init();

    SDL_Texture* background = graphics.loadTexture("img\\day.jpg");
    //SDL_Texture* yard = graphics.loadTexture("img\\yard.png");

    Mouse yard;
    yard.texture = graphics.loadTexture("img\\yard.png");
    yard.x = 0;
    yard.y = 0;

    Sprite moving_player;
    SDL_Texture* movingPlayerTexture = graphics.loadTexture(MOVING_PLAYER_FILE);
    moving_player.init(movingPlayerTexture, MOVING_PLAYER_FRAMES, MOVING_PLAYER_CLIPS);

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) quit = true;
        }
        moving_player.tick();

        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if (currentKeyStates[SDL_SCANCODE_LEFT]) 
        {
            yard.turnEast();
            SDL_RenderCopyEx(graphics.renderer, yard.texture, NULL, NULL, 180.0, NULL, SDL_FLIP_HORIZONTAL);
        }
        if (currentKeyStates[SDL_SCANCODE_RIGHT])
        {
            yard.turnWest();
            graphics.renderFlippedTexture(yard.texture, yard.x, yard.y, SDL_FLIP_VERTICAL);
        }

        yard.move();
        graphics.prepareScene(background);
        render(yard, graphics);
        graphics.render(225, 400, moving_player);
        graphics.presentScene();
        SDL_Delay(100);
        yard.dx = yard.dy = 0;
    }
    SDL_DestroyTexture(movingPlayerTexture); movingPlayerTexture = nullptr;

    graphics.quit();
    return 0;
}