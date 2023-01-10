//
// Created by Bram on 13/04/2022.
//

#ifndef INC_3DSBUILDTEMPLATE_BOX_H
#define INC_3DSBUILDTEMPLATE_BOX_H
#include "box2d/box2d.h"
#include "raylib.h"

//class Box {
//public:
//    b2BodyDef bodyDef;
//    b2Body* body;
//    b2PolygonShape shape;
//    b2FixtureDef fixturedef;
//
//    b2Vec2 size;
//    b2Vec2 renderSize;
//    Color color;
//
//
//public:
//    Box();
//    Box(b2Vec2 position, b2Vec2 size, b2World* world);
//    Box(b2Vec2 position, b2Vec2 size,Color color, b2World *world);
//    Box(b2Vec2 position, b2Vec2 size, b2World *world, bool isStatic);
//    Box(b2Vec2 position, b2Vec2 size, Color color, b2World* world, bool isStatic);
//};
//struct boxData{
//    Color color;
//    b2Vec2 size;
//};


enum ObjectType{
    BOX,
    LINE,
    CIRCLE,
    POLYGON
};

struct ObjectData{
    Color color;
    ObjectType type;
};

//make boxData extend ObjectData
struct boxData : ObjectData{
    Texture2D texture;
    b2Vec2 size;
};


#endif //INC_3DSBUILDTEMPLATE_BOX_H
