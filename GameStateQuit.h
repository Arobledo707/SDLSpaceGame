#pragma once
#include "GameState.h"
class Player;

class GameStateQuit :
    public GameState
{
public:
    GameStateQuit(SDL_Renderer * ren, SDL_Event *event, Player* player, ResourceManager* resources);
    ~GameStateQuit();

    void Enter(GameStateMachine* gsm) override;
    bool Update() override;
    void Exit() override;
private:
	Player* m_pPlayer;
};

