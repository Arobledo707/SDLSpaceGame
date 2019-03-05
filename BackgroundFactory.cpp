#include "BackgroundFactory.h"
#include "ResourceManager.h"
#include "Constants.h"

BackgroundFactory::BackgroundFactory(ResourceManager* pResources, SDL_Renderer* pRen)
	:m_pResources(pResources), m_pRen(pRen)
{
}


BackgroundFactory::~BackgroundFactory()
{
}

Background * BackgroundFactory::SpawnMenuBackground()
{
	Background* pBackground = new StaticBackground(m_pRen, m_pResources->GetTexture(k_menu));
	return pBackground;
}

Background * BackgroundFactory::SpawnGamePlayBackground()
{
	Background* pBackground = new Background(m_pRen, m_pResources->GetTexture(k_scrollingBackground));
	return pBackground;
}
