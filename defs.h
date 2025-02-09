#ifndef _DEFS__H
#define _DEFS__H

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Brother! May i have some oat?";

const char* MOVING_PLAYER_FILE = "img\\Moving_Player.png";
const int MOVING_PLAYER_CLIPS[][4] = {
    {  0, 0,150,100},
    {150, 0,150,100},
    {300, 0,150,100},
    {450, 0,150,100},
};
const int MOVING_PLAYER_FRAMES = sizeof(MOVING_PLAYER_CLIPS) / sizeof(int) / 4;

#endif