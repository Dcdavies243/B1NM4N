//Project Includes
#include "WallRight.h"
#include "Player.h"
#include "Framework/AssetManager.h"

WallRight::WallRight()
	: SpriteObject() //Initialise parent class

{

}

void WallRight::SetSprite(int _currentLevel)
{
	if (_currentLevel == 1)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/Level1WallRight.png"));
	}
	else if (_currentLevel == 2)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/Level2WallLeft.png"));
	}
	else if (_currentLevel == 3)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/Level2StoneFloor.png"));
	}
}
