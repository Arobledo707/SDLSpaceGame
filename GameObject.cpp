#include "GameObject.h"
#include <random>
#include "Constants.h"


GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Draw()
{
    SDL_RenderCopy(m_pRen, m_pTexture, &m_src, &m_dst);
}

void GameObject::TakeDamage()
{
    m_health -= 1;
}

void GameObject::Spawn()
{
    int maxSpawn = k_windowWidth - m_src.w;
    std::random_device randDevice;
    std::mt19937 generator(randDevice());
    std::uniform_int_distribution<int> distr(k_windowMin, maxSpawn);

    m_x = distr(generator);
    m_y = -m_src.h;
}
