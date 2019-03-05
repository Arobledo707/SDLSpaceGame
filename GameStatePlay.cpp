#include "GameStatePlay.h"
#include "GameStateMachine.h"
#include "GameStateQuit.h"
#include "Background.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Player.h"
#include "Wingman.h"
#include "GameStateUpgrade.h"
#include "Constants.h"
#include "Projectile.h"
#include "ProjectileFactory.h"
#include "EnemyFactory.h"
#include "ObserverUI.h"
#include "Collisions.h"
#include "BackgroundFactory.h"
#include "Typedefs.h"

#include <iostream>

// Sets Up play state
GameStatePlay::GameStatePlay(SDL_Renderer * ren, SDL_Event *event, Player* player, ResourceManager* resources)
{
	m_pResources = resources;
    m_pRen = ren;
    m_pEvent = event;
    m_pObserver = new ObserverUI(player, m_pRen);
    m_pPlayer = player;

	BackgroundFactory BGFactory(m_pResources, m_pRen);
	m_pBackground = BGFactory.SpawnGamePlayBackground();
}


GameStatePlay::~GameStatePlay() 
{
	delete m_pObserver;
	//delete m_pPlayer;
}

void GameStatePlay::Enter(GameStateMachine * gsm)
{
    GameState::Enter(gsm);

}

// plays updates everything in the game
bool GameStatePlay::Update()
{
    EnemyFactory eFactory(m_pRen, m_projectiles, m_pResources);
    //m_pPlayer->m_hasHelper = true;

    // Wingman was not completed
    // Supposed to be purchasable upgrade for -player that is friendly ai

    //if (m_pPlayer != nullptr && m_pPlayer->HasHelper())
    //{
    //    //m_players.push_back(new Wingman(k_wingman, m_pRen, m_pEvent));
    //    m_pWingman = new Wingman(k_wingman, m_pRen, m_pEvent);
    //}

    m_pPlayer->ResetSpawn();

    //if (m_pWingman)
    //{
    //    m_pWingman->ResetSpawn();
    //}

    int startTime = SDL_GetTicks();
    int newTime = startTime;
    int oldTime = newTime;
    float levelTime;
    float deltaTime;
    float spawnTimer{ 0 };

    bool gamePlay{ true };

    while (gamePlay)
    {
        // creates delta time and level time
        // and enemy spawn timer
        newTime = SDL_GetTicks();
        deltaTime = (newTime - oldTime) / 1000.0f;
        levelTime = (SDL_GetTicks() - startTime) / 1000.0f;
        spawnTimer += deltaTime;

        //std::cout << levelTime <<  '\t' <<  deltaTime <<  '\t' << spawnTimer<< '\n';

        if (spawnTimer >= 2.2f)
        {
            m_entities.push_back(eFactory.SpawnEnemy());
            spawnTimer = 0;
        }
        
        while (SDL_PollEvent(m_pEvent))
        {
            int x = 0;
            int y = 0;
            switch (m_pEvent->type)
            {
            case SDL_QUIT:
				m_pPlayer->KillObject();
				break;
                // Handles player movement and firing
            case SDL_KEYDOWN:
                switch (m_pEvent->key.keysym.sym)
                {
                case SDLK_SPACE:
                    m_pPlayer->HasFired(m_projectiles);
                    break;
                case SDLK_w:
                    y -= k_playerMoveSpeed;
                    break;
                case SDLK_a:
                    x -= k_playerMoveSpeed;
                    break;
                case SDLK_s:
                    y += k_playerMoveSpeed;
                    break;
                case SDLK_d:
                    x += k_playerMoveSpeed;
                    break;
                case SDLK_RETURN:
                    gamePlay = false;
                    break;
                case SDLK_ESCAPE:
                    break;
                }
            }
            // updates players location
            m_pPlayer->SetDST(x, y);
        }

		UpdateGameObjects(deltaTime);

		Draw();

        //observer draws UI
        // Should also have score but not completed

        // if level timer reaches the limit then the level is over
        if (levelTime > k_levelTimer || m_pPlayer->IsDead())
        {
            gamePlay = false;
        }

        oldTime = newTime;
    }

    if (m_pPlayer->IsDead())
    {
        m_stateMachine->ChangeState<GameStateQuit>(m_pRen, m_pEvent, m_pPlayer, m_pResources);
        return false;
    }
    m_stateMachine->ChangeState<GameStateUpgrade>(m_pRen, m_pEvent, m_pPlayer, m_pResources);
    return true;
}

void GameStatePlay::Exit()
{

    for (auto it = m_projectiles.begin(); it != m_projectiles.end(); )
    {
        delete *it;
        it = (m_projectiles.erase(it));
    }

    for (auto it = m_entities.begin(); it != m_entities.end(); )
    {
        delete *it;
        it = (m_entities.erase(it));
    }
    delete m_pBackground;
    delete m_pWingman;
    m_pWingman = nullptr;
}

void GameStatePlay::UpdateGameObjects(float deltaTime)
{
	// checks to see if enemys health is less or equal to 0 or position is out of bounds
	for (auto entitiy = m_entities.begin(); entitiy != m_entities.end(); )
	{
		if ((*entitiy)->GetLocation().y > k_windowHeight || (*entitiy)->GetHealth() <= 0)
		{
			delete *entitiy;
			entitiy = (m_entities.erase(entitiy));
		}
		else
		{
			(*entitiy)->Update(deltaTime);
			// checks players and enemies collision
			if (Collisions::AreOverLapping(m_pPlayer->GetCollider(), (*entitiy)->GetCollider()))
			{
				m_pPlayer->TakeDamage();
				(*entitiy)->TakeDamage();
			}
			++entitiy;
		}
	}


	// updates projectiles locations and deletes if out of bounds
	// Doesn't check collisions yet
	for (auto it = m_projectiles.begin(); it != m_projectiles.end(); )
	{
		if ((*it)->CheckInBounds())
			//if ((*it)->GetLocation().y <  -k_projectileHeight || (*it)->GetLocation().y >  k_windowHeight)
		{
			delete *it;
			it = (m_projectiles.erase(it));
		}
		else
		{
			(*it)->Update(deltaTime);
			++it;
		}
	}

	m_pBackground->Update();
}

void GameStatePlay::Draw()
{
	        SDL_RenderClear(m_pRen);
        m_pBackground->Draw();
	m_pPlayer->Draw();

	for (GameObject* entitiy : m_entities)
	{
		entitiy->Draw();
	}
	for (Projectile* proj : m_projectiles)
	{
		if (proj)
		{
			proj->Draw();
		}
	}
	m_pObserver->DrawUI();
	SDL_RenderPresent(m_pRen);
}
