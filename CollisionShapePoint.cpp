#include "CollisionShapePoint.h"



CollisionShapePoint::CollisionShapePoint()
{
    m_type = Type::Point;
}

CollisionShapePoint::CollisionShapePoint(int x, int y)
    : m_x((float)x), m_y((float)y)
{
}


CollisionShapePoint::~CollisionShapePoint()
{

}
