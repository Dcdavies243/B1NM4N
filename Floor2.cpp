//Project Includes
#include "Floor2.h"
#include "Player.h"
#include "Framework/AssetManager.h"

Floor2::Floor2()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Level2Floor.png"));
}

