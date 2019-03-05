#pragma once
#include <list>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "ResourceManager.h"


class Enemy;
class Player;
class Projectile;
class GameState;
class Background;

class GameStateMachine
{
public:
    enum class State
    {
        Menu,
        Play,
        Upgrade,
        GameOver,
        Quit
    };

    GameStateMachine();
    ~GameStateMachine();

    int Init();
    void Update();

    void CleanUp();
    void ChangeState(State newState);

    template<typename T>
    void ChangeState(SDL_Renderer * ren, SDL_Event *event, Player* player, ResourceManager* resources);

private:

    GameState* m_pGameState;

    SDL_Window *m_pWin;
    SDL_Renderer *m_pRen;
    SDL_Event* m_pEvent;
    Background* m_pBackground;
    Player* m_pPlayer;

	ResourceManager* m_pResources;

    int m_score;

};



template <typename T>
void GameStateMachine::ChangeState(SDL_Renderer * ren, SDL_Event *event, Player* player, ResourceManager* resources)
{
    T* newState = new T(ren, event, player, resources);

    // Make sure that the type passed is within the bounds of sanity
    if (reinterpret_cast<GameState*>(newState) == nullptr)
    {
        return;
    }

    if (m_pGameState != nullptr)
    {
        m_pGameState->Exit();
        delete m_pGameState;
    }

    m_pGameState = newState;
    m_pGameState->Enter(this);
}