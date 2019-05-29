//Project Includes
#include "Leaves.h"
#include "Framework/AssetManager.h"

Leaves::Leaves()
	: SpriteObject() //Initialise parent class

//Constructor
{
	//Set Sprite
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Leaves.png"));

}