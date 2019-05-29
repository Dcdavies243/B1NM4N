//Project Includes
#include "RustGirder.h"
#include "Framework/AssetManager.h"

RustGirder::RustGirder()
	: SpriteObject() //Initialise parent class

//Constructor
{
	//Set sprite
	m_sprite.setTexture(AssetManager::GetTexture("graphics/GirderRust.png"));

}

void RustGirder::SetSprite(int _currentLevel)
{
	//Set sprite based on Level
	//Levels 1 and 4
	if (_currentLevel == 1 || _currentLevel == 4)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/GirderRust.png"));
	}
	//Level 2
	else if (_currentLevel == 2)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/TreeInternal.png"));
	}
	//Level 3
	else if (_currentLevel == 3)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/ColumnBack.png"));
	}
}
