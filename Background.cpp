#include "Background.h"
#include "Constants.h"
#include <SDL_image.h>
#include "Log.h"


// Is scrolling background
Background::Background(SDL_Renderer *ren, SDL_Texture* pTexture)
{
    m_pRen = ren;
    m_pTexture = pTexture;
    if (SDL_QueryTexture(m_pTexture, nullptr, nullptr, nullptr, nullptr) != 0)
    {
        LOG_SDL_ERROR("QueryTexture");
    }

    posB.y = -k_windowHeight;
}

Background::~Background()
{
}

void Background::Draw()
{
    SDL_Rect dstA{}, dstB{};

    dstA.y = posA.y;
    dstA.w = k_windowWidth;
    dstA.h = k_windowHeight;

    dstB.y = posB.y;
    dstB.w = k_windowWidth;
    dstB.h = k_windowHeight;

    SDL_RenderCopy(m_pRen, m_pTexture, nullptr, &dstA);
    SDL_RenderCopy(m_pRen, m_pTexture, nullptr, &dstB);
}

void Background::Update()
{
    posA.y += m_kScrollSpeed;
    posB.y += m_kScrollSpeed;

    if (posA.y >= k_windowHeight)
    {
        posA.y -= (2 * k_windowHeight);
    }

    if (posB.y >= k_windowHeight)
    {
        posB.y -= (2 * k_windowHeight);
    }
}