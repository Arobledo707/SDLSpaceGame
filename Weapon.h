#pragma once
#include <list>
#include "ProjectileFactory.h"
#include <SDL_mixer.h>

class Projectile;
class Weapon
{
public:
    Weapon(ResourceManager* pResources);
    ~Weapon();
    void Fire(GameObject* character, std::list<Projectile*> &proj);
protected:
    ProjectileFactory m_projFact;
    Mix_Chunk* m_pFire;

	ResourceManager* m_pResources;
};

