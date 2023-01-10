//
// Created by Bram on 20/04/2022.
//

#include "WorldUtil.h"

void addBody(b2Vec2 pos, b2Vec2 size, b2World* world,Color color, bool isStatic) {
    b2BodyDef bodyDef;
    auto* data = new boxData();
    data->texture = LoadTexture(ASSETS_PATH"/cat.png");
    data->color = color;
    data->size = size;
    if(!isStatic){
        bodyDef.type = b2_dynamicBody;
    }else{
        bodyDef.type = b2_staticBody;
    }
    bodyDef.position.Set(pos.x , pos.y);
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(data);
    b2Body* body = world->CreateBody(&bodyDef);
//    bodyDef.userData = (void*)data;

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(size.x, size.y);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
}

void addLine(b2Vec2 pos1, b2Vec2 pos2, b2World* world) {
    b2BodyDef bd;
    b2Body* ground = world->CreateBody(&bd);

    b2EdgeShape shape;
    shape.SetTwoSided(pos1, pos2);
    ground->CreateFixture(&shape, 0.0f);
}

b2Vec2 PixelsToWorld(b2Vec2 pos) {
    return {map(pos.x, 0, SCREEN_WIDTH, -WORLD_WIDTH, WORLD_WIDTH),map(pos.y, 0, WORLD_HEIGHT, -WORLD_HEIGHT, WORLD_HEIGHT)};
}