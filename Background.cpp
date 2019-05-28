//Project Includes
#include "Background.h"
#include "Framework/AssetManager.h"

Background::Background()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/BackgroundLevel1.png"));

}

void Background::SetSprite(int _currentLevel)
{
	if (_currentLevel == 1)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/BackgroundLevel1.png"));
	}
	else if (_currentLevel == 2)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/BackgroundLevel2.png"));
	}
	else if (_currentLevel == 3)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/BackgroundLevel3.png"));
	}
	else if (_currentLevel == 4)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/Victory.png"));
	}
}