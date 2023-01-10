

#include "MouseUtil.h"

b2Body *getMouseBody(b2World *world, Vector2 mousePos) {
    b2Vec2 worldMousePos = PixelCoordsToWorldCoords(b2Vec2(mousePos.x, mousePos.y));
    b2AABB aabb;
    aabb.lowerBound = worldMousePos - b2Vec2(0.001f, 0.001f);
    aabb.upperBound = worldMousePos + b2Vec2(0.001f, 0.001f);

    std::vector<b2Body *> bodies;
    // make a b2QueryCallback to get all bodies in the aabb
    class QueryCallback : public b2QueryCallback {
    public:
        std::vector<b2Body *> *bodies;

        QueryCallback(std::vector<b2Body *> *bodies) {
            this->bodies = bodies;
        }

        bool ReportFixture(b2Fixture *fixture) {
            bodies->push_back(fixture->GetBody());
            return true;
        }
    };
    world->QueryAABB(new QueryCallback(&bodies), aabb);
    if (bodies.size() > 0) {
        return bodies[0];
    } else {
        return nullptr;
    }
}

