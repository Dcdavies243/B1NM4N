//Project Includes
#include "UI.h"
#include "Player.h"
#include "Framework/AssetManager.h"

UI::UI()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/UI_None.png"));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 1.5);


}

void UI::Update(sf::Time _frameTime)
{
	m_sprite.setPosition(m_player->GetPosition());

	SetSprite();
}

void UI::SetSprite()
{
	// Set sprite based on player input
	//Fan Selected
	if (m_player->ToolSelectFan())
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/UI_Fan.png"));
	}
	//Treatrs Selected
	else if (m_player->ToolSelectTreats())
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/UI_Treat.png"));
	}

}

void UI::SetPlayer(Player* _player)
{
	m_player = _player;
}