//Project Includes
#include "Foreground.h"
#include "Framework/AssetManager.h"

Foreground::Foreground()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/ForegroundTest.png"));

}