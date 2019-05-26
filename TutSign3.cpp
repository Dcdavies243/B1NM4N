//Project Includes
#include "TutSign3.h"
#include "Framework/AssetManager.h"

TutSign3::TutSign3()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/TutSign3.png"));

}