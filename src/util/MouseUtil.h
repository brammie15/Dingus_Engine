//
// Created by Bram on 08/01/2023.
//

#ifndef RAYLIB_TEMPLATE_MOUSEUTIL_H
#define RAYLIB_TEMPLATE_MOUSEUTIL_H

#include <raylib.h>
#include <raymath.h>
#include <box2d/box2d.h>
#include <vector>
#include "b2Vec2Helpers.h"

b2Body *getMouseBody(b2World *world, Vector2 mousePos);


#endif //RAYLIB_TEMPLATE_MOUSEUTIL_H
