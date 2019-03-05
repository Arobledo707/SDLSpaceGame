#pragma once
#include "GameObject.h"
#include <list>
#include "Typedefs.h"

class ResourceManager;
struct SDL_Renderer;

class Justice :
	public GameObject
{
public:
	Justice(SDL_Renderer* pRen, ResourceManager* pResources, ProjContainer* projectiles);
	~Justice();

	void Update(const float dt) override;
private:
	ResourceManager* m_pResources;
	ProjContainer* m_projContainer;
	Mix_Chunk* pChunk;

	const int k_rocketLimit;
	int m_rocketsSpawned;
	float m_spawnTimer = 0;
};

