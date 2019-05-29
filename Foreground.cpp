//Project Includes
#include "Foreground.h"
#include "Framework/AssetManager.h"

Foreground::Foreground()
	: SpriteObject() //Initialise parent class

//Constructor
{
	//Set Sprite
	m_sprite.setTexture(AssetManager::GetTexture("graphics/ForegroundTest.png"));

}
