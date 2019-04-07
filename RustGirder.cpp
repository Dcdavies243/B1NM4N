//Project Includes
#include "RustGirder.h"
#include "Framework/AssetManager.h"

RustGirder::RustGirder()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/GirderRust.png"));

}