//Project Includes
#include "TutSign.h"
#include "Framework/AssetManager.h"

TutSign::TutSign()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/TutSign1.png"));

}