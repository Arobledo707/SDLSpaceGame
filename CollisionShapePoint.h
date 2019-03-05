#pragma once
#include "CollisionShape.h"
class CollisionShapePoint :
    public CollisionShape
{
public:
    CollisionShapePoint();
    CollisionShapePoint(int x, int y);
    ~CollisionShapePoint();

    float GetX() { return m_x; }
    float GetY() { return m_y; }

private:
    float m_x;
    float m_y;
};

