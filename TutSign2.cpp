//Project Includes
#include "TutSign2.h"
#include "Framework/AssetManager.h"

TutSign2::TutSign2()
	: SpriteObject() //Initialise parent class
//Constructor
{
	//Set Sprite
	m_sprite.setTexture(AssetManager::GetTexture("graphics/TutSign2.png"));

}