//
// Created by Bram on 18/04/2022.
//

#include "RenderUtil.h"
#include "rlgl.h"           // Required for: Vertex definition
#include "MathUtil.h"
#include <utility>

Vector2 normalize(b2Vec2 &vec2);

void polygon(std::vector<b2Vec2> verts, Color color) {
    using N = int;
    std::vector<std::vector<b2Vec2>> polygon;
    polygon.emplace_back();
//    polygon.push_back({{100, 0}, {100, 100}, {0, 100}, {0, 0}});
//    polygon.push_back({{75, 25}, {75, 75}, {25, 75}, {25, 25}}); Rule 1: if it doesnt work, Don't touch it
    polygon.at(0) = std::move(verts);


//    for (int i = 0; i < verts->Length(); ++i) {
////        polygon[0].push_back(verts[i]);
//        polygon[0] = verts;
//    }

    std::vector<N> indices = mapbox::earcut<N>(polygon);
    for (int i = 0; i < indices.size(); ++i) {
        int index = indices[i];
        b2Vec2 currentVertex = getVertex(polygon, index);
    }

    for (int i = 0; i < indices.size(); i += 3) {
        int index1 = indices[i];
//        printf("index1: %i \n", index1);
        int index2 = indices[i + 1];
//        printf("index2: %i \n", index2);
        int index3 = indices[i + 2];
//        printf("index3: %i \n", index3);
        b2Vec2 vert1 = getVertex(polygon, index3);
        b2Vec2 vert2 = getVertex(polygon, index2);
        b2Vec2 vert3 = getVertex(polygon, index1);

        DrawTriangle(b2Vec2ToVector2(vert1), b2Vec2ToVector2(vert2), b2Vec2ToVector2(vert3),color);
        DrawLine(vert1.x, vert1.y, vert2.x, vert2.y, BLACK);
        DrawLine(vert2.x, vert2.y, vert3.x, vert3.y, BLACK);
        DrawLine(vert3.x, vert3.y, vert1.x, vert1.y, BLACK);
    }

//    for (int i = 0; i < polygon[0].size(); ++i) {
//        for (int j = 0; j < polygon[0].size(); ++j) {
//            DrawLine(polygon.at(0)[i].x,polygon.at(0)[i].y,polygon.at(0)[j].x,polygon.at(0)[j].y, BLACK);
//        }
//    }


//    for (int i = 0; i < indices.size(); i += 2) {
//        int index1 = indices[i];
//        int index2 = indices[i + 1];
//
//        b2Vec2 pos1 = getVertex(polygon, index1);
////        printf("pos1: X: %i Y: %i \n", pos1.x ,pos1.y);
//        b2Vec2 pos2 = getVertex(polygon, index2);
////        printf("pos2: X: %i Y: %i \n", pos2.x ,pos2.y);
//
//        DrawLine(pos1.x, pos1.y, pos2.x, pos2.y,BLACK);
//    }
//    b2Vec2 temp = {100,69};
//    printf("shit: X: %i Y: %i \n", b2Vec2ToVector2(temp).x, b2Vec2ToVector2(temp).y);
//    DrawCircle(b2Vec2ToVector2(temp).x, b2Vec2ToVector2(temp).y, 10,GREEN);
//    DrawTriangle(Vector2{100,100}, Vector2{400,200}, Vector2{300,250}, ORANGE);

}
void renderBody(b2Body* body, b2Fixture* fixture) {
    auto* poly = (b2PolygonShape*)fixture->GetShape();
    b2Transform xf = body->GetTransform();
    int vertexCount = poly->m_count;
    if(vertexCount == 2){
        b2Vec2 v1 = b2Mul(xf, poly->m_vertices[0]);
        b2Vec2 v2 = b2Mul(xf, poly->m_vertices[1]);
        DrawLine(v1.x, v1.y, v2.x, v2.y, BLACK);
        return;
    }
    if(vertexCount == 0) return;

//    printf("%i",poly->m_vertices->Length());
    std::vector<b2Vec2> verticies;
    for (int i = 0; i < vertexCount; ++i) {
        b2Vec2 renderPos = WorldCoordsToPixelCoords(b2Mul(xf, poly->m_vertices[i]));
        verticies.push_back(renderPos);
    }
    boxData* data = reinterpret_cast<boxData*>(body->GetUserData().pointer);
    if(data){
        if(data->texture.id != 0){ //Only do if i have a texture
            int amountOfVerts = verticies.size();
            rlSetTexture(data->texture.id);

            rlBegin(RL_QUADS);

            rlColor4f(1,1,1,1);
            Vector2 texCoords[4] = {
                    {0,1},
                    {1,1},
                    {1,0},
                    {0,0}
            };

            for (int i = 0; i < amountOfVerts; ++i) {
//                rlTexCoord2f(map(verticies[i].x / data->texture.width, 0,10, 0,1), map(verticies[i].y / data->texture.height, 0,10, 0,1));
                rlTexCoord2f(texCoords[i].x, texCoords[i].y);
                rlVertex2f(verticies[i].x, verticies[i].y);
            }
            rlEnd();
            rlSetTexture(0);
            return;
        }else{
            Color c = data->color;
            polygon(verticies, c);
            return;
        }
    }
    polygon(verticies, ORANGE);
}

b2Vec2 getVertex(std::vector<std::vector<b2Vec2>> polygon, int index){
//    return polygon[0].at(index);
    if(index > polygon[0].size()){
        return polygon[1][index - polygon[0].size()];
    }else{
        return polygon[0][index];
    }
}

b2Vec2 WorldCoordsToPixelCoords(b2Vec2 pos){
    return {pos.x * M2P + GetScreenWidth()/2, -(pos.y * M2P) + GetScreenHeight()/2};
}

b2Vec2 PixelCoordsToWorldCoords(b2Vec2 pos){
//    return {((pos.x * P2M + GetScreenWidth()/2) ), (pos.y * P2M + GetScreenHeight()/2)};

    //converts pixel coords to world coords
    b2Vec2 worldPos = {pos.x - GetScreenWidth()/2, pos.y - GetScreenHeight()/2};
    worldPos.x = worldPos.x * P2M;
    worldPos.y = -worldPos.y * P2M;
    return worldPos;
}

Vector2 b2Vec2ToVector2(b2Vec2 vec){
    Vector2 out;
    out.x = vec.x;
    out.y = vec.y;
    return out;
}

void drawRectangle(float x1, float y1, float x2, float y2) {
    DrawLine(x1, y1, x2, y1, BLACK);
    DrawLine(x2, y1, x2, y2, BLACK);
    DrawLine(x2, y2, x1, y2, BLACK);
    DrawLine(x1, y2, x1, y1, BLACK);
}


namespace mapbox {
    namespace util {

        template <>
        struct nth<0, b2Vec2> {
            inline static auto get(const b2Vec2 &t) {
                return t.x;
            };
        };
        template <>
        struct nth<1, b2Vec2> {
            inline static auto get(const b2Vec2 &t) {
                return t.y;
            };
        };

    } // namespace util
} // namespace mapbox


//void DrawTexturePoly(Texture2D texture, Vector2 center, Vector2 *points, Vector2 *texcoords, int pointCount, Color tint)
//{
//    rlSetTexture(texture.id);
//
//    // Texturing is only supported on RL_QUADS
//    rlBegin(RL_QUADS);
//
//    rlColor4ub(tint.r, tint.g, tint.b, tint.a);
//
//    for (int i = 0; i < pointCount - 1; i++)
//    {
//        rlTexCoord2f(0.5f, 0.5f);
//        rlVertex2f(center.x, center.y);
//
//        rlTexCoord2f(texcoords[i].x, texcoords[i].y);
//        rlVertex2f(points[i].x + center.x, points[i].y + center.y);
//
//        rlTexCoord2f(texcoords[i + 1].x, texcoords[i + 1].y);
//        rlVertex2f(points[i + 1].x + center.x, points[i + 1].y + center.y);
//
//        rlTexCoord2f(texcoords[i + 1].x, texcoords[i + 1].y);
//        rlVertex2f(points[i + 1].x + center.x, points[i + 1].y + center.y);
//    }
//    rlEnd();
//
//    rlSetTexture(0);
//}