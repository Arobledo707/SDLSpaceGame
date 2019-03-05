#include "UIText.h"
#include <SDL.h>

//creates text UI Element
UIText::UIText(SDL_Renderer* ren, int x, int y, int width, int height, const char* text, TTF_Font* font)
    :m_pRen(ren), m_pFont(font), m_width(width), m_height(height), m_x(x), m_y(y)
{
    Init(text);
}

UIText::~UIText()
{
    SDL_FreeSurface(m_pSurface);
    SDL_DestroyTexture(m_pTexture);
}

// Sets up Texture and makes ready to use
void UIText::Init(const char* text)
{
    m_pSurface = TTF_RenderUTF8_Solid(m_pFont, text, k_textColor);
    m_pTexture = SDL_CreateTextureFromSurface(m_pRen, m_pSurface);
    m_dst = SDL_Rect{ m_x, m_y, m_width, m_height };
}

void UIText::Draw()
{

    SDL_RenderCopy(m_pRen, m_pTexture, nullptr, &m_dst);
}
