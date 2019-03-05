#pragma once
class Projectile;
class GameObject;
class ResourceManager;

class ProjectileFactory
{
    enum ProjectileType
    {
        player,
        enemy
    };

public:
    ProjectileFactory(ResourceManager* pResources);
    ~ProjectileFactory();

    Projectile* SpawnProjectile(GameObject* character);

private:
	ResourceManager* m_pResources;
};

