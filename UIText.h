#pragma once
#include "UIElement.h"
#include <SDL_ttf.h>

class UIText
{
public:
    UIText(SDL_Renderer* ren, int x, int y, int width, int height, const char* text, TTF_Font* font);
    ~UIText();

    void Init(const char* text);
    void Draw();

private:
    SDL_Renderer* m_pRen;

    SDL_Surface* m_pSurface;
    SDL_Texture* m_pTexture;
    int m_x;
    int m_y;
    int m_width;
    int m_height;

    TTF_Font* m_pFont;
    SDL_Rect m_dst;

    const SDL_Color k_textColor = { 0, 255, 255, 255 };
};

