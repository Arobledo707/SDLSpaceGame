#pragma once
#include "StaticBackground.h"

class ResourceManager;

class BackgroundFactory
{
public:
	BackgroundFactory(ResourceManager* pResources, SDL_Renderer* pRen);
	~BackgroundFactory();

	Background* SpawnMenuBackground();
	Background* SpawnGamePlayBackground();

private:
	ResourceManager* m_pResources;
	SDL_Renderer* m_pRen;
};

