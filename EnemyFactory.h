#pragma once
#include "GameObject.h"
#include <list>

#include "ResourceManager.h"
struct SDL_Renderer;
class Projectile;

class EnemyFactory
{
public:
    EnemyFactory(SDL_Renderer* ren, std::list<Projectile*> &proj, ResourceManager* resources);
    ~EnemyFactory();

    GameObject* SpawnEnemy();
	GameObject* SpawnRocket();
private:

    SDL_Renderer* m_pRen;
    std::list<Projectile*> *m_projectiles;
	ResourceManager* m_pResourceManager;
};

