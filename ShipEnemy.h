#pragma once
#include "GameObject.h"
#include "Weapon.h"
struct SDL_Renderer;

class ShipEnemy :
    public GameObject
{
public:
    ShipEnemy(SDL_Renderer* ren, std::list<Projectile*> *proj, SDL_Texture* pTexture, ResourceManager* pResources);
    ~ShipEnemy();
    void Update(const float dt) override;

private:
    Weapon m_weapon;
    std::list<Projectile*> *m_projectiles;
    const int k_firingTimer;
    float m_timer;
};

