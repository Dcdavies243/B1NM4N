//Project Includes
#include "RustGirder.h"
#include "Framework/AssetManager.h"

RustGirder::RustGirder()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/GirderRust.png"));

}

void RustGirder::SetSprite(int _currentLevel)
{
	if (_currentLevel == 1 || _currentLevel == 4)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/GirderRust.png"));
	}
	else if (_currentLevel == 2)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/TreeInternal.png"));
	}
	else if (_currentLevel == 3)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/ColumnBack.png"));
	}
}
