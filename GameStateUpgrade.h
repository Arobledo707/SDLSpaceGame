#pragma once
#include "GameState.h"
#include <SDL_ttf.h>

class Background;
class Player;
class UIText;

class GameStateUpgrade :
    public GameState
{
public:
    GameStateUpgrade(SDL_Renderer * ren, SDL_Event* event, Player* player, ResourceManager* resources);
    ~GameStateUpgrade();

    void Enter(GameStateMachine* gsm);
    bool Update();
    void Exit();
private:
    Player* m_pPlayer;
    UIText* m_pText;
    TTF_Font* m_pFont;
};

