#include "EnemyFactory.h"
#include "SpiderEnemy.h"
#include "ShipEnemy.h"
#include "Constants.h"
#include "Rocket.h"
#include "Justice.h"
#include <SDL.h>
#include <random>


EnemyFactory::EnemyFactory(SDL_Renderer* ren, ProjContainer &proj, ResourceManager* resources)
	:m_pRen(ren), m_pResourceManager(resources)
{
	m_projectiles = &proj;
}


EnemyFactory::~EnemyFactory()
{
}

//spawns enemy uses first enemy to last enemy then randomly selects
GameObject* EnemyFactory::SpawnEnemy()
{
	int enemyTypes{ 2 };
	int minEnemy{ 0 };
	GameObject* enemy;

	std::random_device randDevice;
	std::mt19937 generator(randDevice());
	std::uniform_int_distribution<int> distr(minEnemy, enemyTypes);

	switch(distr(generator))
	{
	case 0:
		enemy = new SpiderEnemy(m_pRen, m_pResourceManager->GetTexture(k_spider));
		break;
	case 1:
		enemy = new ShipEnemy(m_pRen, m_projectiles, m_pResourceManager->GetTexture(k_enemyShip), m_pResourceManager);
		break;
	case 2:
		enemy = new Justice(m_pRen, m_pResourceManager, m_projectiles);
		break;
	default:
		enemy = new SpiderEnemy(m_pRen, m_pResourceManager->GetTexture(k_spider));
	}

	return enemy;
}

GameObject * EnemyFactory::SpawnRocket()
{
	GameObject* pRocket = new Rocket(m_pRen, m_pResourceManager->GetTexture(k_rocket));
	return pRocket;
}
