//
// Created by Bram on 18/04/2022.
//

#ifndef RAYLIB_TEMPLATE_RENDERUTIL_H
#define RAYLIB_TEMPLATE_RENDERUTIL_H
#include "box2d/box2d.h"
#include "../earcut.hpp"
#include "raylib.h"
#include "../objects/box.h"
#include <stdio.h>                  // Required for: fopen(), fclose(), fputc(), fwrite(), printf(), fprintf(), funopen()
#include <time.h>
#include "CONSTS.h"



void polygon(std::vector<b2Vec2> verts);
//void renderBox(Box box);
b2Vec2 WorldCoordsToPixelCoords(b2Vec2 pos);
void renderBody(b2Body* body, b2Fixture* fixture);
b2Vec2 getVertex(std::vector<std::vector<b2Vec2>> polygon, int index);
Vector2 b2Vec2ToVector2(b2Vec2 vec);

void drawRectangle(float x1, float y1, float x2, float y2);
#endif //RAYLIB_TEMPLATE_RENDERUTIL_H
