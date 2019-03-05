#pragma once
#include "GameObject.h"
struct SDL_Renderer;

class SpiderEnemy
    : public GameObject
{
public:
    SpiderEnemy(SDL_Renderer* ren, SDL_Texture* pTexture);
    ~SpiderEnemy();

    void Update(const float dt) override;

};

