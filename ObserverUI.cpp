#include "ObserverUI.h"
#include "Player.h"
#include <string>
#include "Constants.h"

ObserverUI::ObserverUI(Player* player, SDL_Renderer* ren)
    :m_pPlayer(player), m_pRen(ren)
{
    m_pFont = TTF_OpenFont(k_textFont, 50);
}


ObserverUI::~ObserverUI()
{
    TTF_CloseFont(m_pFont);
}

void ObserverUI::DrawUI()
{
    DrawHealth();
}

void ObserverUI::DrawHealth()
{
    std::string currentHealth = k_currentHealth + std::to_string(m_pPlayer->GetHealth());
    const char* pChar = currentHealth.c_str();
    m_pHealth = new UIText(m_pRen, 0, k_windowHeight - 20, 75, 25, pChar, m_pFont);
    m_pHealth->Draw();
    delete m_pHealth;

}

void ObserverUI::DrawScore()
{
    m_pPlayer->GetScore();
}
