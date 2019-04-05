//Project Includes
#include "WallRight.h"
#include "Player.h"
#include "Framework/AssetManager.h"

WallRight::WallRight()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Level1WallRight.png"));

}
