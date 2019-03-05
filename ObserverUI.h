#pragma once
#include "UIText.h"
#include <string>
class Player;

class ObserverUI
{
public:
	ObserverUI(Player* player, SDL_Renderer* ren);
	~ObserverUI();
	void DrawUI();
    Player* GetPlayerPointer() { return m_pPlayer; }
private:
	void DrawHealth();
	void DrawScore();

	Player* m_pPlayer;
	SDL_Renderer* m_pRen;
    
    UIText* m_pHealth;
    UIText* m_pScore;

	TTF_Font* m_pFont;

    const std::string k_currentHealth{"Health: "};
};

