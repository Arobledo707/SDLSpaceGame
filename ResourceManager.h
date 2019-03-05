#pragma once
#include <unordered_map>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>


class ResourceManager
{
public:
	ResourceManager(SDL_Renderer* pRenderer);
	~ResourceManager();

	SDL_Texture* GetTexture(std::string filepath);
	Mix_Chunk* GetMixChunk(std::string filepath);

private:
	std::unordered_map<std::string, SDL_Texture*> m_textures;
	SDL_Texture* LoadTexture(std::string filepath);

	std::unordered_map<std::string, Mix_Chunk*> m_mixChunks;
	Mix_Chunk* LoadMixChunk(std::string filepath);

	std::unordered_map<std::string, TTF_Font*> m_fonts;
	TTF_Font* LoadFont(std::string filepath, int textSize);

	SDL_Renderer* m_pRen;
};

