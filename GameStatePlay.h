#pragma once
#include "GameState.h"
#include <vector>
#include <list>

class Background;
class Player;
class Projectile;
class GameObject;

class GameStatePlay :
    public GameState
{
public:
    GameStatePlay(SDL_Renderer * ren, SDL_Event *event, Player* player, ResourceManager* resources);
    ~GameStatePlay();

    virtual void Enter(GameStateMachine* gsm) override;
    virtual bool Update() override;
    virtual void Exit() override;
private:
    Player* m_pPlayer;
    Player* m_pWingman;

	void UpdateGameObjects(float deltaTime);
	void Draw();

    std::list<Projectile*> m_projectiles;
    std::list<GameObject*> m_entities;
    const int k_levelTimer = 30;
};

