//Project Includes
#include "Floor.h"
#include "Player.h"
#include "Framework/AssetManager.h"

Floor::Floor()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/GroundPlacehold.png"));

}
