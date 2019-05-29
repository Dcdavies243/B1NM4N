//Project Includes
#include "FillerBox.h"
#include "Framework/AssetManager.h"

FillerBox::FillerBox()
	: SpriteObject() //Initialise parent class

//Constructor
{
	//Set sprite
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Level1Filler.png"));

}