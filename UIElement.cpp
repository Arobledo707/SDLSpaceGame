#include "UIElement.h"
#include <SDL_image.h>

UIElement::UIElement(SDL_Renderer * ren, SDL_Texture* pTexture)
    : m_pRen(ren), m_pTexture(pTexture)
{
}

UIElement::~UIElement()
{
    m_pRen = nullptr;
}

void UIElement::SetDST(int x, int y)
{
    m_dst = SDL_Rect{ x, y, k_frameWidth, k_frameHeight };
}

// Should be more generic so it can be used for more things
// Sets up Texture for Ship Selection screen
// Should also be refactored and used for upgrade screen
void UIElement::Init()
{
    m_src.w = k_shipWidth;
    m_src.h = k_shipHeight;
}

void UIElement::Draw()
{
    SDL_RenderCopy(m_pRen, m_pTexture, &m_src, &m_dst);
}

//If ship is selected it turns red
// Will also be animation for when player takes damage
void UIElement::Selected(int y)
{
    if (y != m_dst.y)
    {
        m_frameIndex = k_selected;
    }
    else
    {
        m_frameIndex = k_unselected;
    }
    m_src.x = m_frameIndex * k_shipWidth;
}
