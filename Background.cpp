//Project Includes
#include "Background.h"
#include "Framework/AssetManager.h"

Background::Background()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/BackgroundLevel2.png"));

}