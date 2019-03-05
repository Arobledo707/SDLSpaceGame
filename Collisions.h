#pragma once
#include "CollisionShape.h"
#include "CollisionShapeAABB.h"
#include "CollisionShapeCircle.h"

class Collisions
{
public:
    Collisions();
    ~Collisions();

    static bool AreOverLapping(CollisionShape *a, CollisionShape *b);
private:
    static bool AABBOverlapAABB(CollisionShapeAABB *a, CollisionShapeAABB *b);
    static bool CircleOverlapAABB(CollisionShapeCircle *circle, CollisionShapeAABB *aabb);
    static bool PointOverlapAABB(CollisionShapePoint *pt, CollisionShapeAABB *aabb);
};

