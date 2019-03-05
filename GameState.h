#pragma once
#include "ResourceManager.h"
#include <SDL.h>
class Background;
class ObserverUI;
class GameState
{
public:
    GameState();
    virtual ~GameState();

    virtual void Enter(class GameStateMachine* gsm);
    virtual bool Update() = 0;
    virtual void Exit() = 0;

protected:
    GameStateMachine* m_stateMachine;
    SDL_Renderer *m_pRen;
    SDL_Event* m_pEvent;
    Background* m_pBackground;
    ObserverUI* m_pObserver;
	ResourceManager* m_pResources;
};