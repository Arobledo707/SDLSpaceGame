#pragma once
#include "GameObject.h"
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include "Constants.h"
#include <list>


class Weapon;
class ResourceManager;

class Player :

    public GameObject
{
public:

	Player(SDL_Texture* pTexture , SDL_Renderer *ren, SDL_Event* event, ResourceManager* pResources);
    virtual ~Player();
    void Update(const float dt) override;
    virtual void SetDST(int x, int y);
    virtual bool HasHelper() { return m_hasHelper; }
    virtual void ResetSpawn();
    virtual void HasFired(std::list<Projectile*> &proj);
    int GetScore() { return m_score; }
    bool m_hasHelper;

protected:
    void CheckLimits();
    int m_score;
    Weapon* m_pCurrentWeap;
    SDL_Event* m_pEvent;
};

