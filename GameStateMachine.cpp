#include "GameStateMachine.h"
#include "Player.h"
#include "Projectile.h"
#include <iostream>
#include "GameStateMachine.h"
#include "GameState.h"
#include "GameStateMenu.h"
#include "GameStatePlay.h"
#include "GameStateQuit.h"
#include "Constants.h"
#include <SDL_image.h>
#include <assert.h>
#define SDL_INIT_FAILURE 1


int GameStateMachine::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return SDL_INIT_FAILURE;
    }

    m_pWin = SDL_CreateWindow("SpaceShooter", 100, 100, 480, 720, NULL);
    m_pRen = SDL_CreateRenderer(m_pWin, -1, SDL_RendererFlags::SDL_RENDERER_PRESENTVSYNC |
        SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();

    if (Mix_Init(MIX_INIT_OGG) != MIX_INIT_OGG)
    {
        std::cout << "Mix Init Error " << std::endl;
    }

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);

    return 0;
}

void GameStateMachine::Update()
{
    while (m_pGameState->Update())
    {
    }
    ChangeState(State::Quit);
}

void GameStateMachine::CleanUp()
{
	delete m_pGameState;
    delete m_pEvent;
    delete m_pPlayer;
	delete m_pResources;
    SDL_DestroyRenderer(m_pRen);
    SDL_DestroyWindow(m_pWin);
    TTF_Quit();

    Mix_CloseAudio();
    Mix_Quit();

    IMG_Quit();

    SDL_Quit();
}

void GameStateMachine::ChangeState(State newState)
{
    if (m_pGameState)
    {
        m_pGameState->Exit();
        delete m_pGameState;
    }
    switch (newState)
    {
    case State::Menu:
		// null player????
        m_pGameState = new GameStateMenu(m_pRen, m_pEvent, nullptr, m_pResources);
        break;
    case State::Quit:
        m_pGameState = new GameStateQuit(m_pRen, m_pEvent, m_pPlayer, m_pResources);
        break;
    }

    m_pGameState->Enter(this);
}

GameStateMachine::GameStateMachine()
{
    m_pEvent = new SDL_Event;
    Init();
	m_pResources = new ResourceManager(m_pRen);
	assert(m_pResources);
    ChangeState(State::Menu);
}

GameStateMachine::~GameStateMachine()
{

}
