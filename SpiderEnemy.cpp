#include "SpiderEnemy.h"
#include <SDL.h>
#include "Constants.h"
#include "CollisionShapeAABB.h"


SpiderEnemy::SpiderEnemy(SDL_Renderer* ren, SDL_Texture* pTexture)
{
    m_type = GameObject::Type::enemy;
    m_pCollider = new CollisionShapeAABB();
    m_pRen = ren;
	m_pTexture = pTexture;
    //m_pTexture = IMG_LoadTexture(m_pRen, k_sprites);
    m_src.w = k_spiderDimension;
    m_src.h = k_spiderDimension;
    m_health = k_startingAiHealth;
    m_speed = k_spiderSpeed;
    Spawn();
}


SpiderEnemy::~SpiderEnemy()
{
	delete m_pCollider;
	m_pCollider = nullptr;
    //SDL_DestroyTexture(m_pTexture);
}

void SpiderEnemy::Update(const float dt)
{
    m_y += m_speed;
    m_dst = SDL_Rect{ m_x, m_y, k_spiderDimension, k_spiderDimension };

    CollisionShapeAABB* pCollider = dynamic_cast<CollisionShapeAABB*>(m_pCollider);
    pCollider->SetRect(m_dst);

    m_frameTime -= dt;
    //std::cout << "DeltaTime: " << deltaTime << std::endl;

    if (m_frameTime <= 0)
    {
        m_frameTime += m_frameDuration;
        m_tile = ++m_tile % (k_spiderDead - 1);
        m_src.x = m_tile * k_spiderDimension;
    }

    if (m_tile >= k_spiderDead)
    {
        m_tile = 0;
    }

    if (m_health == 0)
    {
        m_src.x = k_spiderDead * k_spiderDimension;
    }

}

