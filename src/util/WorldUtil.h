//
// Created by Bram on 20/04/2022.
//

#ifndef RAYLIB_TEMPLATE_WORLDUTIL_H
#define RAYLIB_TEMPLATE_WORLDUTIL_H
#include "box2d/box2d.h"
#include "raylib.h"
#include "../objects/box.h"
#include "CONSTS.h"
#include "MathUtil.h"

void addBody(b2Vec2 pos, b2Vec2 size, b2World* world, Color color, bool isStatic);
void addLine(b2Vec2 pos1, b2Vec2 pos2, b2World* world);

b2Vec2 PixelsToWorld(b2Vec2 pos);



#endif //RAYLIB_TEMPLATE_WORLDUTIL_H
