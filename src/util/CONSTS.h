//
// Created by Bram on 22/04/2022.
//

#ifndef RAYLIB_TEMPLATE_CONSTS_H
#define RAYLIB_TEMPLATE_CONSTS_H

const int SCREEN_WIDTH = 1820;
const int SCREEN_HEIGHT = 880;
const int M2P = 16;
const float P2M = (1.0f/M2P);

//#define P2M 16
//#define M2P (1/P2M)
const float WORLD_WIDTH  = (SCREEN_WIDTH/2 * P2M);
//const int WORLD_WIDTH = (SCREEN_WIDTH/2 * P2M);
//const int WORLD_HEIGHT = (SCREEN_HEIGHT/2 * P2M);
const float WORLD_HEIGHT = (SCREEN_HEIGHT/2 * P2M);

#endif //RAYLIB_TEMPLATE_CONSTS_H
