#include "GameStateQuit.h"
#include "Player.h"


GameStateQuit::GameStateQuit(SDL_Renderer * ren, SDL_Event *event, Player* player, ResourceManager* resources)
{
	m_pRen = ren;
	m_pResources = resources;
	m_pEvent = event;
	m_pPlayer = player;
}


GameStateQuit::~GameStateQuit()
{
	delete m_pPlayer;
	m_pPlayer = nullptr;
	//delete m_pResources;
	//m_pResources = nullptr;
}

void GameStateQuit::Enter(GameStateMachine * gsm)
{
    GameState::Enter(gsm);
}

// Ends game loop
bool GameStateQuit::Update()
{
    return false;
}

void GameStateQuit::Exit()
{
}
