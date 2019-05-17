//Project Includes
#include "Floor.h"
#include "Player.h"
#include "Framework/AssetManager.h"

Floor::Floor()
	: SpriteObject() //Initialise parent class

{
	
}

void Floor::SetSprite(int _currentLevel)
{
	if (_currentLevel == 1)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/Level1Floor.png"));
	}
	else if (_currentLevel == 2)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/Level2Floor.png"));
	}
}


