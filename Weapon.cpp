#include "Weapon.h"
#include "ProjectileFactory.h"
#include "ResourceManager.h"
#include "Constants.h"

Weapon::Weapon(ResourceManager* pResources)
	:m_pResources(pResources), m_projFact(pResources)
{
    m_pFire = m_pResources->GetMixChunk("Assets/shipfire.wav");
}


Weapon::~Weapon()
{
}

// Fires weapon and spawns projectile into list of projectile*s
// Projectile needs to be refactored to just take a location
void Weapon::Fire(GameObject* character, std::list<Projectile*> &proj)
{
    if (this != nullptr)
    {
        Mix_PlayChannel(-1, m_pFire, 0);
    }
	proj.push_back(m_projFact.SpawnProjectile(character));
}
