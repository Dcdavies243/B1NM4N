//Project Includes
#include "Wall.h"
#include "Player.h"
#include "Framework/AssetManager.h"

Wall::Wall()
	: SpriteObject() //Initialise parent class

{

}

void Wall::SetSprite(int _currentLevel)
{
	if (_currentLevel == 1)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/Level1WallLeft.png"));
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
