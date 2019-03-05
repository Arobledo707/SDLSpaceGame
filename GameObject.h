#pragma once
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

class StateMachine;
struct SDL_Renderer;
struct SDL_Texture;
class Projectile;
class CollisionShape;

// base class for all gameobjects that are interactable
class GameObject
{
    friend class Projectile;
public:

	// type def stuff here
	//namespace then enum
    enum Type
    {
        player,
        enemy
    };

    GameObject();
    virtual ~GameObject();
    virtual void Update(const float dt) = 0;
    virtual void Draw();
    SDL_Rect GetLocation() { return m_dst; }
    CollisionShape* GetCollider() { return m_pCollider; }
    int GetType() const { return m_type; }
    int GetHealth() const { return m_health; }
	bool IsDead() const { return m_health <= 0; }
	void KillObject() { m_health = 0; }
    void TakeDamage();


protected:
    virtual void Spawn();

    int m_y;
    int m_x;
    int m_health;
    int m_speed;
    int m_tile;
    float m_frameDuration{ .2f };
    float m_frameTime;
    const char* k_sprites;

    Type m_type;

    StateMachine* m_pState;
    SDL_Renderer* m_pRen;
    SDL_Texture* m_pTexture;

    CollisionShape* m_pCollider;

    SDL_Rect m_src;
    SDL_Rect m_dst;
};

