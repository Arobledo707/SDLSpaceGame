#pragma once
#include <SDL.h>


class Background
{
private:
    const int m_kScrollSpeed{ 2 };
    SDL_Point posA, posB;
protected:
    SDL_Texture* m_pTexture;
    SDL_Renderer* m_pRen;
public:
    Background(SDL_Renderer *ren, SDL_Texture* pTexture);
    virtual ~Background();

    virtual void Draw();
    virtual void Update();
};

