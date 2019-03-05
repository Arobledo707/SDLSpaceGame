#include "GameState.h"



GameState::GameState()
{
}


GameState::~GameState()
{
}

void GameState::Enter(GameStateMachine * gsm)
{
	delete m_stateMachine;
    m_stateMachine = gsm;
}
