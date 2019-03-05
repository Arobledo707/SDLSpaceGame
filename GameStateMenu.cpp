#include "GameStateMenu.h"
#include "GameStateMachine.h"
#include "GameStatePlay.h"
#include "GameStateQuit.h"
#include "StaticBackground.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Constants.h"
#include "Player.h"
#include "ObserverUI.h"
#include "ResourceManager.h"

#include <string>
#include <iostream>
// Creates background, Arrow that points to ships and ship UI elements and text
GameStateMenu::GameStateMenu(SDL_Renderer* ren, SDL_Event* event, Player* player, ResourceManager* resources)
    : m_pEvent(event)
{
	m_pResources = resources;
    m_pRen = ren;
    m_pBackground = new StaticBackground(m_pRen, m_pResources->GetTexture(k_menu));
    m_pArrow = new UIElement(m_pRen, m_pResources->GetTexture("Assets/arrow.png"));
    m_pArrow->Init();
    m_options.push_back(shipOptions
	(new UIElement(m_pRen, m_pResources->GetTexture(k_ship1)), shipChoices::ship1));
    m_options.push_back(shipOptions
	(new UIElement(m_pRen, m_pResources->GetTexture(k_ship2)), shipChoices::ship2));
    m_options.push_back(shipOptions
	(new UIElement(m_pRen, m_pResources->GetTexture(k_ship3)), shipChoices::ship3));


    for (shipOptions option : m_options)
    {
        option.first->Init();
    }

    m_pFont = TTF_OpenFont(k_textFont, 50);
    m_pText = new UIText(m_pRen, 1, 1, 480, 100, "Choose your ship!", m_pFont);
}


GameStateMenu::~GameStateMenu()
{
	delete m_pText;
	TTF_CloseFont(m_pFont);
	for (shipOptions option : m_options)
	{
		delete option.first;
	}
}

void GameStateMenu::Enter(GameStateMachine * gsm)
{
    GameState::Enter(gsm);
}

bool GameStateMenu::Update()
{
    int shipChoice{ 0 };
    const char* chosenSprite{ k_ship1 };
    int arrowY{ 225 };
    int arrowX{ 100 };
    m_pArrow->SetDST(arrowX, arrowY);
    while (!m_chosenShip)
    {
        while (SDL_PollEvent(m_pEvent))
        {
            switch (m_pEvent->type)
            {
            case SDL_QUIT:
                //m_stateMachine->ChangeState<GameStateQuit>(m_pRen, m_pEvent, m_pPlayer, m_pResources);
                return false;
                break;
            case SDL_KEYDOWN:
                switch (m_pEvent->key.keysym.sym)
                {
                case SDLK_w:
                    shipChoice -= 1;
                    break;
                case SDLK_s:
                    shipChoice += 1;
                    break;
                case SDLK_RETURN:
                    m_chosenShip = true;
                    break;
                case SDLK_ESCAPE:
                    m_chosenShip = true;
                    break;
                }
            }
        }

        if (shipChoice < 0)
        {
            shipChoice = k_shipChoices;
        }
        else if (shipChoice > k_shipChoices)
        {
            shipChoice = 0;
        }

        // sets arrow location and chosen sprite
        // Should be refactored and not have magic constants
        switch (shipChoice)
        {
        case 0:
            chosenSprite = k_ship1;
            arrowY = 225;
            break;
        case 1:
            chosenSprite = k_ship2;
            arrowY = 375;
            break;
        case 2:
            chosenSprite = k_ship3;
            arrowY = 525;
            break;
        }

        SDL_RenderClear(m_pRen);

        m_pBackground->Draw();
        m_pText->Draw();
        m_pArrow->SetDST(arrowX, arrowY);
        m_pArrow->Draw();

        int shipChoiceX = 275;
        int shipChoiceY = 225;
        // adds 150 to shipChoice Y to seperate ships
        for (shipOptions option : m_options)
        {
            option.first->SetDST(shipChoiceX, shipChoiceY);
            option.first->Selected(arrowY);
            option.first->Draw();
            shipChoiceY += 150;
        }


        SDL_RenderPresent(m_pRen);
    }

    Player* pPlayer = new Player(m_pResources->GetTexture(chosenSprite), m_pRen, m_pEvent, m_pResources);
    m_stateMachine->ChangeState<GameStatePlay>(m_pRen, m_pEvent, pPlayer, m_pResources);
    return true;
}

void GameStateMenu::Exit()
{
    delete m_pBackground;
    delete m_pArrow;
}
