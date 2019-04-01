//Project Includes
#include "Wall.h"
#include "Player.h"
#include "Framework/AssetManager.h"

Wall::Wall()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/GroundPlacehold.png"));

}
