//Project Includes
#include "Background.h"
#include "Framework/AssetManager.h"

Background::Background()
	: SpriteObject() //Initialise parent class

//Constructor
{
	// Setting sprite
	m_sprite.setTexture(AssetManager::GetTexture("graphics/BackgroundLevel1.png"));

}

void Background::SetSprite(int _currentLevel)
{
	// Set sprite based on Level

	//Level 1 Sprite
	if (_currentLevel == 1)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/BackgroundLevel1.png"));
	}
	//Level 2 Sprite
	else if (_currentLevel == 2)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/BackgroundLevel2.png"));
	}
	//Level 3 Sprite
	else if (_currentLevel == 3)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/BackgroundLevel3.png"));
	}
	//Level 4 Sprite
	else if (_currentLevel == 4)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/Victory.png"));
	}
}