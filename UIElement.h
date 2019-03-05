#pragma once

#include <SDL.h>
#include "Constants.h"

class UIElement
{
public:
    UIElement(SDL_Renderer *ren, SDL_Texture* pTexture);
    virtual ~UIElement();
    virtual void SetDST(int x, int y);
    virtual void Init();
    void Draw();
    virtual void Selected(int y);
protected:

    SDL_Texture *m_pTexture;
    SDL_Renderer *m_pRen;

    SDL_Rect m_src;
    SDL_Rect m_dst;

    const int k_frameWidth{ 75 };
    const int k_frameHeight{ 80 };

    const int k_selected{ 1 };
    const int k_unselected{ 0 };
    int m_frameIndex;
};

