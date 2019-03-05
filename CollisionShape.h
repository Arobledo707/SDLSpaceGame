#pragma once
class CollisionShape
{
public:
    CollisionShape();
    virtual ~CollisionShape();

    enum class Type
    {
        AABB,
        Circle,
        Point
    };
    Type GetType() { return m_type; }

protected:
    Type m_type;
};

