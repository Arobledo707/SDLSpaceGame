#include "ShipEnemy.h"
#include "Constants.h"
#include "CollisionShapeAABB.h"


ShipEnemy::ShipEnemy(SDL_Renderer * ren, std::list<Projectile*> *proj, SDL_Texture* pTexture, ResourceManager* pResources)
    :k_firingTimer(2), m_weapon(pResources)
{
    m_type = GameObject::Type::enemy;
    m_projectiles = proj;

    m_pRen = ren;
	m_pTexture = pTexture;
    m_src.w = k_enemyShipWidth;
    m_src.h = k_enemyShipHeight;
    m_health = k_startingAiHealth;
    m_speed = k_enemyShipSpeed;
    m_pCollider = new CollisionShapeAABB();
    Spawn();
}

ShipEnemy::~ShipEnemy()
{
	delete m_pCollider;
	m_pCollider = nullptr;
}

// handles ship location, firing and collider location
void ShipEnemy::Update(const float dt)
{
    m_y += m_speed;
    m_dst = SDL_Rect{ m_x, m_y, k_enemyShipWidth, k_enemyShipHeight };

    m_timer += dt;
    if (m_timer > k_firingTimer)
    {
		// I dont remember what this is
		// need to remember what this is doing
		// why am i casting??????????????????????????????????????????????????????????????????????????????
        m_weapon.Fire(dynamic_cast<GameObject*>(this), (*m_projectiles));
        m_timer = 0;
    }

    CollisionShapeAABB* pCollider = dynamic_cast<CollisionShapeAABB*>(m_pCollider);
    pCollider->SetRect(m_dst);
}
