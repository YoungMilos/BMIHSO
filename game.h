#pragma once
#include "defs.h"
#include "graphics.h"
#define INITIAL_SPEED 10

struct Mouse {
    int x, y;
    SDL_Texture* texture;
    int dx = 0, dy = 0;
    int speed = INITIAL_SPEED;
    void move() {
        x += dx;
        y += dy;
    }
    void turnNorth() {
        dy = -speed;
        dx = 0;
    }
    void turnSouth() {
        dy = speed;
        dx = 0;
    }
    void turnWest() {
        dy = 0;
        dx = -speed;
    }
    void turnEast() {
        dy = 0;
        dx = speed;
    }
};

void render(const Mouse& mouse, Graphics& graphics) {
    graphics.renderTexture(mouse.texture, mouse.x, mouse.y);
}