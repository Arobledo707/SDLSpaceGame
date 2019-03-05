#include "Rocket.h"
#include "CollisionShape.h"


Rocket::Rocket(SDL_Renderer* pRen, SDL_Texture* pTexture)
	:Projectile(pTexture, nullptr)
{
	SDL_Log("Boop!");
	m_type = GameObject::Type::enemy;
	m_pCollider = new CollisionShapeAABB();
	m_pRen = pRen;
	m_pTexture = pTexture;
	m_src.w = k_rocketWidth;
	m_src.h = k_rocketHeight;
	m_health = k_startingAiHealth;
	Init(Type::enemy);
	Spawn();
}


Rocket::~Rocket()
{
	delete m_pCollider;
	m_pCollider = nullptr;
}

void Rocket::Update(const float dt)
{
	m_y += m_speed;
	m_dst = SDL_Rect{ m_x, m_y, k_rocketWidth, k_rocketHeight };

	CollisionShapeAABB* pCollider = dynamic_cast<CollisionShapeAABB*>(m_pCollider);
	pCollider->SetRect(m_dst);

	m_frameTime -= dt;
	//std::cout << "DeltaTime: " << deltaTime << std::endl;

	if (m_frameTime <= 0)
	{
		m_frameTime += m_frameDuration;
		m_tile = ++m_tile % (4);
		m_src.x = m_tile * k_rocketWidth;
	}

	if (m_tile >= 4)
	{
		m_tile = 0;
	}

	//if (m_health == 0)
	//{
	//	m_src.x = 4 * k_projectileWidth;
	//}
}
