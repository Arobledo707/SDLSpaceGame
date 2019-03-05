
#include "Player.h"
#include "Constants.h"
#include "Weapon.h"
#include "CollisionShapeAABB.h"

Player::Player(SDL_Texture* pTexture, SDL_Renderer *ren, SDL_Event* event, ResourceManager* pResources)
    : m_pEvent(event)
{
    this->k_sprites = k_sprites;
    m_pRen = ren;
	m_pTexture = pTexture;
    m_src.w = k_shipWidth;
    m_src.h = k_shipHeight;
    m_type = Type::player;
    m_pCollider = new CollisionShapeAABB();
    m_pCurrentWeap = new Weapon(pResources);
    m_src.x = 0 * k_shipWidth;
}


Player::~Player()
{
    //SDL_DestroyTexture(m_pTexture);
    delete m_pCollider;
    m_pCollider = nullptr;
    delete m_pCurrentWeap;
    m_pCurrentWeap = nullptr;
}

void Player::Update(const float dt)
{
}

// Sets players location and collider location ib game
void Player::SetDST(int x, int y)
{

    m_x += x;
    m_y += y;

    CheckLimits();

    m_dst = SDL_Rect{ m_x, m_y, k_shipWidth, k_shipHeight };
    CollisionShapeAABB* pCollider = dynamic_cast<CollisionShapeAABB*>(m_pCollider);
    pCollider->SetRect(m_dst);
}

void Player::ResetSpawn()
{
    m_health = k_startingLife;
    m_x = k_playerSpawnX;
    m_y = k_playerSpawnY;
}

// fires weapon
void Player::HasFired(std::list<Projectile*> &proj)
{
    m_pCurrentWeap->Fire(dynamic_cast<GameObject*>(this), proj);
}

//Checks plays location limits
void Player::CheckLimits()
{
    if (m_x < k_windowMin)
    {
        m_x = k_windowMin;
    }
    else if (m_x > (k_windowWidth - k_shipWidth))
    {
        m_x = (k_windowWidth - k_shipWidth);
    }

    if (m_y < (k_windowMin + k_shipHeight))
    {
        m_y = (k_windowMin + k_shipHeight);
    }
    else if (m_y > (k_windowHeight - k_shipHeight))
    {
        m_y = (k_windowHeight - k_shipHeight);
    }
}
