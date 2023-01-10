//
// Created by Bram on 13/04/2022.
//

#ifndef INC_3DSBUILDTEMPLATE_B2VEC2HELPERS_H
#define INC_3DSBUILDTEMPLATE_B2VEC2HELPERS_H
#include "box2d/box2d.h"
#include "raylib.h"

b2Vec2 b2vec2Mul(b2Vec2 vec, float num);
b2Vec2 b2vec2Mul(b2Vec2 vec, b2Vec2 num);
b2Vec2 coordPixelsToWorld(float pixelX, float pixelY);
b2Vec2 PixelCoordsToWorldCoords(b2Vec2 pos);
b2Vec2 swapXY(b2Vec2 vec);
Vector2 b2Vec2ToVector2(b2Vec2 vec);
b2Vec2 Vector2Tob2Vec2(Vector2 vec);
#endif //INC_3DSBUILDTEMPLATE_B2VEC2HELPERS_H
