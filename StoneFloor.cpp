//Project Includes
#include "StoneFloor.h"
#include "Player.h"
#include "Framework/AssetManager.h"

StoneFloor::StoneFloor()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Level2StoneFloor.png"));
}