#include "Collisions.h"
#include "CollisionShapeAABB.h"


Collisions::Collisions()
{
}


Collisions::~Collisions()
{
}

bool Collisions::AreOverLapping(CollisionShape* a, CollisionShape* b)
{
    if (a->GetType() == CollisionShape::Type::AABB)
    {
        CollisionShapeAABB* pAabbA = dynamic_cast<CollisionShapeAABB*>(a);
        if (b->GetType() == CollisionShape::Type::AABB)
        {
            CollisionShapeAABB* pAabbB = dynamic_cast<CollisionShapeAABB*>(b);
            return AABBOverlapAABB(pAabbA, pAabbB);
        }
        else if (b->GetType() == CollisionShape::Type::Circle)
        {
			CollisionShapeCircle* pAabbB = dynamic_cast<CollisionShapeCircle*>(b);
			return CircleOverlapAABB(pAabbB, pAabbA);
        }
		else if(b->GetType() == CollisionShape::Type::Point)
		{
			CollisionShapePoint* pAabbB = dynamic_cast<CollisionShapePoint*>(b);
			return PointOverlapAABB(pAabbB, pAabbA);
		}
    }
    else if (a->GetType() == CollisionShape::Type::Circle)
    {
        if (b->GetType() == CollisionShape::Type::AABB)
        {
			
        }
    }
	else if(a->GetType() == CollisionShape::Type::Point)
	{
		CollisionShapePoint* pAabbA = dynamic_cast<CollisionShapePoint*>(a);
		if(b->GetType() == CollisionShape::Type::AABB)
		{
			CollisionShapeAABB* pAabbB = dynamic_cast<CollisionShapeAABB*>(b);
			return PointOverlapAABB(pAabbA, pAabbB);
		}
		else if(b->GetType() == CollisionShape::Type::Circle)
		{

		}
	}

    return false;
}

bool Collisions::AABBOverlapAABB(CollisionShapeAABB* a, CollisionShapeAABB* b)
{
    auto aCorners = a->GetCorners();

    for (auto corner : aCorners)
    {
        if (PointOverlapAABB(&corner, b))
        {
            return true;
        }
    }

    auto bCorners = b->GetCorners();

    for (auto corner : bCorners)
    {
        if (PointOverlapAABB(&corner, a))
        {
            return true;
        }
    }

    return false;
}

bool Collisions::CircleOverlapAABB(CollisionShapeCircle* circle, CollisionShapeAABB* aabb)
{
    return false;
}

bool Collisions::PointOverlapAABB(CollisionShapePoint* pt, CollisionShapeAABB* aabb)
{
    return (pt->GetX() > aabb->GetRekt().x && pt->GetX() <= aabb->GetRekt().x + aabb->GetRekt().w
        && pt->GetY() > aabb->GetRekt().y && pt->GetY() <= aabb->GetRekt().y + aabb->GetRekt().h);
}
