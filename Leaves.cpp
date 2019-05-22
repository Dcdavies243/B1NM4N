//Project Includes
#include "Leaves.h"
#include "Framework/AssetManager.h"

Leaves::Leaves()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Leaves.png"));

}