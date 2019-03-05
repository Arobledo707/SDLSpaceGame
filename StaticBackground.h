#pragma once
#include "Background.h"


class StaticBackground :
    public Background
{
public:
    StaticBackground(SDL_Renderer *ren, SDL_Texture* pTexture);
    ~StaticBackground();

    void Draw() override;
    void Update();

};

