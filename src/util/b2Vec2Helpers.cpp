//
// Created by Bram on 13/04/2022.
//

#include "b2Vec2Helpers.h"

b2Vec2 b2vec2Mul(b2Vec2 vec, float num){
    b2Vec2 calc = vec;
    calc.x *= num;
    calc.y *= num;
    return calc;
}

b2Vec2 b2vec2Mul(b2Vec2 vec, b2Vec2 num){
    b2Vec2 calc = vec;
    calc.x *= num.x;
    calc.y *= num.y;
    return calc;
}
b2Vec2 swapXY(b2Vec2 vec){
    b2Vec2 temp = vec;
    float tempx = vec.x;
    vec.x = vec.y;
    vec.y = tempx;
    return vec;
}

b2Vec2 coordPixelsToWorld(float pixelX, float pixelY) {
//    float transX = SCREEN_WIDTH/2;
//    float transY = SCREEN_HEIGHT/2;
//    float worldX = map(pixelX, transX, transX+SCALING_FACTOR, 0.0f, 1.0f);
//    float worldY = pixelY;
////    if (yFlip == -1.0f) worldY = map(pixelY,SCREEN_HEIGHT,0.0f,0.0f,SCREEN_HEIGHT);
//    worldY = map(worldY, transY, transY+SCALING_FACTOR, 0.0f, 1.0f);
//    return b2Vec2(worldX,worldY);
}

b2Vec2 Vector2ToB2Vec2(Vector2 vec) {
    return b2Vec2(vec.x, vec.y);
}

Vector2 B2Vec2toVector2(b2Vec2 vec) {
    return Vector2{vec.x, vec.y};
}
