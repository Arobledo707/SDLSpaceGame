#pragma once
#include "CollisionShape.h"
#include "CollisionShapePoint.h"
#include <SDL.h>
#include <vector>
class CollisionShapeAABB :
    public CollisionShape
{
public:
    CollisionShapeAABB();
    ~CollisionShapeAABB();

    std::vector<CollisionShapePoint> GetCorners();
    void SetRect(const SDL_Rect rect);
    SDL_Rect GetRekt() const;
private:
    SDL_Rect m_rect;
};

