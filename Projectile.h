#pragma once
#include "GameObject.h"

class Projectile :
    public GameObject
{
public:
    Projectile(SDL_Texture* pTexture, GameObject* character);
    virtual ~Projectile();
    virtual void Update(const float dt) override;
	virtual bool CheckInBounds();
protected:
    void Init(const int type);
	//mistakes were made
	//redo this

};

