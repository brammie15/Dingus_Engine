#include "box2d/box2d.h"
#include "objects/box.h"
#include "util/RenderUtil.h"
#include "util/b2Vec2Helpers.h"
#include "util/WorldUtil.h"
#include "util/MathUtil.h"
#include "util/CONSTS.h"
#include "util/MouseUtil.h"


b2Vec2 getPoint(int pointCount, int currPoint){
    float pointAngle = 360/ pointCount;

    float anglePoint = currPoint * pointAngle * DEG2RAD;

    return {(cos(anglePoint) * 200) + SCREEN_WIDTH/2, (sin(anglePoint) * 200) + SCREEN_HEIGHT/2};
}




int main(){

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    SetTargetFPS(60);
    Texture2D texture = LoadTexture(ASSETS_PATH"/cat.png");
    b2Vec2 gravity(0.0f, -10.0f);
//    std::unique_ptr<b2World> world = std::make_unique<b2World>(gravity);
    b2World world(gravity);
    //8addLine(PixelsToWorld({10, SCREEN_HEIGHT-10}), PixelsToWorld({SCREEN_WIDTH - 10, SCREEN_HEIGHT - 10}), &world);
    addBody(b2Vec2_zero, b2Vec2{5,5},&world,GREEN, false);

    //add borders to the edge of the screen
    addLine(b2Vec2{-WORLD_WIDTH, -WORLD_HEIGHT}, b2Vec2{WORLD_WIDTH, -WORLD_HEIGHT}, &world);
//    addLine(PixelsToWorld({0, 0}), PixelsToWorld({SCREEN_WIDTH, 0}), &world);
    addLine(PixelsToWorld({SCREEN_WIDTH, 0}), PixelsToWorld({SCREEN_WIDTH, SCREEN_HEIGHT}), &world);
    addLine(PixelsToWorld({0, SCREEN_HEIGHT}), PixelsToWorld({0, 0}), &world);

    int32 velocityIterations = 24;
    int32 positionIterations = 24;
    Vector2 startPos;
    Vector2 endPos;
    while (!WindowShouldClose()){
        world.Step(GetFrameTime(), velocityIterations, positionIterations);
        if(IsKeyDown(KEY_SPACE)){
            b2Vec2 worldPos = PixelCoordsToWorldCoords(b2Vec2{GetMousePosition().x, GetMousePosition().y});
            addBody(worldPos, b2Vec2{random(1, 5.0f), random(1, 5.0f)}, &world, ColorFromHSV(random(0,360), 360, 360), false);
        }
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            startPos = GetMousePosition();
        }
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            endPos = GetMousePosition();
            b2Vec2 worldPos1 = PixelCoordsToWorldCoords(b2Vec2{startPos.x, startPos.y});
            b2Vec2 worldPos2 = PixelCoordsToWorldCoords(b2Vec2{endPos.x, endPos.y});
            Color randomColor = ColorFromHSV(random(0,360), 360, 360);
            //average of the vectors
            b2Vec2 center = (worldPos1 + worldPos2);
            center.x /= 2;
            center.y /= 2;

            b2Vec2 size = worldPos1 - worldPos2;
            size.x = abs(size.x)/2;
            size.y = abs(size.y)/2;

            addBody(center, size, &world, randomColor, false);
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (b2Body* b = world.GetBodyList(); b; b = b->GetNext()){
            renderBody(b, b->GetFixtureList());
        }

        DrawCircle(GetMousePosition().x, GetMousePosition().y, 5, RED);
        DrawCircle(startPos.x, startPos.y, 5, RED);
        DrawCircle(endPos.x, endPos.y, 5, RED);
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
            DrawLine(startPos.x, startPos.y, GetMousePosition().x, GetMousePosition().y, RED);
            drawRectangle(startPos.x, startPos.y, GetMousePosition().x, GetMousePosition().y);
        }

//        DrawTexture(texture, 0, 0, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
