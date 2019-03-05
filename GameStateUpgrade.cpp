#include "GameStateUpgrade.h"
#include "GameStateMachine.h"
#include "GameStatePlay.h"
#include "GameStateQuit.h"
#include "UIText.h"
#include "Constants.h"
#include "Background.h"
#include "StaticBackground.h"

// Should be upgrade screen that player can use currency to purchase new weapons, AI teammate
// For now it just is a midpoint between levels
GameStateUpgrade::GameStateUpgrade(SDL_Renderer * ren, SDL_Event* event, Player* player, ResourceManager* resources)
{
	m_pResources = resources;
    m_pRen = ren;
    m_pEvent = event;
    m_pBackground = new StaticBackground(m_pRen, m_pResources->GetTexture(k_menu));
    m_pPlayer = player;
    m_pFont = TTF_OpenFont(k_textFont, 50);
    m_pText = new UIText(m_pRen, 0, k_windowHeight / 2, k_windowWidth, 50, "Press Enter to Continue ", m_pFont);
}


GameStateUpgrade::~GameStateUpgrade()
{
	//crash when moving to upgrrade state
    TTF_CloseFont(m_pFont);
}

void GameStateUpgrade::Enter(GameStateMachine * gsm)
{
    GameState::Enter(gsm);
}

bool GameStateUpgrade::Update()
{
    bool gamePlay{ true };
    while (gamePlay)
    {
        while (SDL_PollEvent(m_pEvent))
        {
            switch (m_pEvent->type)
            {
            case SDL_QUIT:
                m_stateMachine->ChangeState<GameStateQuit>(m_pRen, m_pEvent, m_pPlayer, m_pResources);
                return false;
            case SDL_KEYDOWN:
                switch (m_pEvent->key.keysym.sym)
                {
                case SDLK_w:
                    break;
                case SDLK_s:
                    break;
                case SDLK_RETURN:
                    gamePlay = false;
                    break;
                case SDLK_ESCAPE:
                    break;
                }
            }
        }

        m_pBackground->Update();

        SDL_RenderClear(m_pRen);

        m_pBackground->Draw();
        m_pText->Draw();

        SDL_RenderPresent(m_pRen);
    }

    m_stateMachine->ChangeState<GameStatePlay>(m_pRen, m_pEvent, m_pPlayer, m_pResources);
    return true;
}

void GameStateUpgrade::Exit()
{
    delete m_pText;
    delete m_pBackground;
}
