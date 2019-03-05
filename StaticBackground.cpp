#include "StaticBackground.h"
#include <SDL_image.h>


StaticBackground::StaticBackground(SDL_Renderer *ren, SDL_Texture* pTexture)
    :Background(ren, pTexture)
{
}


StaticBackground::~StaticBackground()
{
}

void StaticBackground::Draw()
{
    SDL_RenderCopy(m_pRen, m_pTexture, nullptr, nullptr);
}

void StaticBackground::Update()
{
}
