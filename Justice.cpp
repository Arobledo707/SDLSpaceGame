#include "Justice.h"
#include "Rocket.h"
#include "ProjectileFactory.h"
#include "ResourceManager.h"
#include "CollisionShapePoint.h"

Justice::Justice(SDL_Renderer* pRen, ResourceManager* pResources, ProjContainer* projectiles)
    :m_pResources(pResources), m_projContainer(projectiles), k_rocketLimit(15)

{
	m_type = Type::enemy;
	m_pCollider = new CollisionShapePoint();
	m_health = 1000;
	m_pRen = pRen;
	pChunk = m_pResources->GetMixChunk("Assets/Justice_Rains_From_Above_.wav");
	Mix_PlayChannel(-1, pChunk, 0);
}


Justice::~Justice()
{
	delete m_pCollider;
	m_pCollider = nullptr;
}

void Justice::Update(const float dt)
{
	m_spawnTimer += dt;
	if (k_rocketLimit > m_rocketsSpawned && m_spawnTimer > .078f)
	{
		m_projContainer->push_back(new Rocket(m_pRen, m_pResources->GetTexture(k_rocket)));
		SDL_Log("Rocket Spawned!");
		++m_rocketsSpawned;
		m_spawnTimer = 0;
	}

	else if(k_rocketLimit == m_rocketsSpawned)
	{
		m_health = 0;
		SDL_Log("All Rockets Spawned!!");
	}
}
