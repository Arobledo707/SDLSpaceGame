#pragma once
#include "GameState.h"
#include "UIElement.h"
#include <vector>
#include <map>
#include <SDL.h>
#include <SDL_ttf.h>
#include "UIText.h"

class Background;
class Player;
class UIElement;

typedef std::pair<UIElement*, int> shipOptions;

class GameStateMenu :
    public GameState
{
public:
    GameStateMenu(SDL_Renderer * ren, SDL_Event *event, Player* player, ResourceManager* resources);
    ~GameStateMenu();

    enum shipChoices
    {
        ship1,
        ship2,
        ship3
    };

    virtual void Enter(GameStateMachine* gsm) override;
    virtual bool Update() override;
    virtual void Exit() override;
private:

    const char* GetShipSprite(int choice);

    SDL_Renderer *m_pRen;
    SDL_Event* m_pEvent;
    Background* m_pBackground;
    Player* m_pPlayer;

    std::vector<shipOptions> m_options;
    UIElement* m_pArrow;
    TTF_Font* m_pFont;
    UIText* m_pText;

    int m_selectedShip;
    bool m_chosenShip;
};

