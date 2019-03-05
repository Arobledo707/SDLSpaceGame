#include "ResourceManager.h"
#include <assert.h>
#include "Constants.h"


ResourceManager::ResourceManager(SDL_Renderer* pRenderer)
	:m_pRen(pRenderer)
{
	static int count = 0;
	++count;
	assert(count == 1);
}


ResourceManager::~ResourceManager()
{
	for(auto iterator = m_textures.begin(); iterator!= m_textures.end();)
	{
		SDL_DestroyTexture(iterator->second);
		iterator = (m_textures.erase(iterator));
	}

	for (auto iterator = m_mixChunks.begin(); iterator != m_mixChunks.end();)
	{
		Mix_FreeChunk(iterator->second);
		iterator = (m_mixChunks.erase(iterator));
	}

}

SDL_Texture * ResourceManager::GetTexture(std::string filepath)
{
	auto iterator = m_textures.find(filepath);
	if (iterator == m_textures.end())
	{
		SDL_Texture* pTexture = LoadTexture(filepath);
		m_textures.emplace(filepath, pTexture);
		return pTexture;
	}
	
	return iterator->second;
}

Mix_Chunk * ResourceManager::GetMixChunk(std::string filepath)
{
	auto iterator = m_mixChunks.find(filepath);
	if (iterator == m_mixChunks.end())
	{
		Mix_Chunk* pChunk = LoadMixChunk(filepath);
		m_mixChunks.emplace(filepath, pChunk);
		return pChunk;
	}

	return iterator->second;
}



SDL_Texture* ResourceManager::LoadTexture(std::string filepath)
{
	SDL_Texture* pTexture = IMG_LoadTexture(m_pRen, filepath.c_str());
	return pTexture;
}

Mix_Chunk * ResourceManager::LoadMixChunk(std::string filepath)
{
	Mix_Chunk* pChunk = Mix_LoadWAV(filepath.c_str());
	return pChunk;
}

TTF_Font * ResourceManager::LoadFont(std::string filepath, int textSize)
{
	TTF_Font* pFont = TTF_OpenFont(filepath.c_str(), textSize);
	return pFont;
}
