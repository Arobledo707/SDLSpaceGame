#pragma once
#include "Projectile.h"
#include <SDL.h>
#include "Constants.h"
#include "CollisionShapeAABB.h"

struct SDL_Renderer;
struct SDL_Texture;

class Rocket :
	public Projectile
{
public:
	Rocket(SDL_Renderer* pRen, SDL_Texture* pTexture);
	~Rocket();

	void Update(const float deltaTime) override;
};

