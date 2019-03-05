#include "Projectile.h"
#include <SDL.h>
#include "Constants.h"

// TODO
// refactor so projectile only knows what type it is and what position to spawn at
// useful so new weapons can be implemented that shoot multiple projectiles
// Needs not to be friend class anymore
Projectile::Projectile(SDL_Texture* pTexture, GameObject* character)
{
	m_health = 1;
	m_src.w = k_projectileWidth;
	m_src.h = k_projectileHeight;
	if (character)
	{
		m_pRen = character->m_pRen;
		m_pTexture = pTexture;
		m_x = character->m_x + ((character->m_src.w - m_src.w) / 2);
		m_y = character->m_y;
		Init(character->m_type);
	}
}


Projectile::~Projectile()
{
}

void Projectile::Update(const float dt)
{
    m_y += m_speed;

    m_dst = SDL_Rect{ m_x, m_y, k_projectileWidth, k_projectileWidth };

    m_frameTime -= dt;
    //std::cout << "DeltaTime: " << deltaTime << std::endl;

    if (m_frameTime <= 0)
    {
        m_frameTime += m_frameDuration;
        m_tile = ++m_tile % (4);
        m_src.x = m_tile * k_projectileWidth;
    }

}

void Projectile::Init(const int type)
{
    switch (type)
    {
    case Type::player:
        m_type = Type::player;
        m_speed = k_playerProjSpeed;
        break;
    case Type::enemy:
        m_type = Type::enemy;
        m_speed = 5;
        break;
    }
}

//redo >>>>>>>>>><<<<<<<<<<<<<<><><>><><>>><><>><><><><><
bool Projectile::CheckInBounds()
{
	return (GetLocation().y < -m_src.h || GetLocation().y > k_windowHeight);
}
