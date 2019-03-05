#include "CollisionShapeAABB.h"



CollisionShapeAABB::CollisionShapeAABB()
{
    m_type = Type::AABB;
}


CollisionShapeAABB::~CollisionShapeAABB()
{
}

std::vector<CollisionShapePoint> CollisionShapeAABB::GetCorners()
{
    std::vector<CollisionShapePoint> corners;
    corners.push_back(CollisionShapePoint(m_rect.x, m_rect.y));
    corners.push_back(CollisionShapePoint(m_rect.x + m_rect.w, m_rect.y));
    corners.push_back(CollisionShapePoint(m_rect.x + m_rect.w, m_rect.y + m_rect.h));
    corners.push_back(CollisionShapePoint(m_rect.x, m_rect.y + m_rect.h));

    return corners;
}

void CollisionShapeAABB::SetRect(const SDL_Rect rect)
{
    m_rect = rect;
}

SDL_Rect CollisionShapeAABB::GetRekt() const
{
    return m_rect;
}
