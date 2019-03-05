#include "ProjectileFactory.h"
#include "Projectile.h"
#include "GameObject.h"
#include "Constants.h"
#include "ResourceManager.h"


// Projectile Factory
ProjectileFactory::ProjectileFactory(ResourceManager* pResources)
	: m_pResources(pResources)
{
}


ProjectileFactory::~ProjectileFactory()
{
}

// spawns type of projectile based on character that shot it
Projectile * ProjectileFactory::SpawnProjectile(GameObject* character)
{
	SDL_Texture* pTexture = nullptr;
    switch (character->GetType())
    {
    case ProjectileType::player:
		pTexture = m_pResources->GetTexture(k_projectile);
        break;
    case ProjectileType::enemy:
		pTexture = m_pResources->GetTexture(k_enemyprojectile);
        break;
    }

    Projectile* proj = new Projectile(pTexture, character);

    return proj;
}
