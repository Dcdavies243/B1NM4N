#include "Player.h"
#include "Framework/AssetManager.h"
#include "Floor.h"
#include "TreatsTool.h"

//Constants
#define SPEED 200.0f

TreatsTool::TreatsTool()
	: SpriteObject() //Initialise base class
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/TreatsPlacehold.png"));

	//TODO: Set up the animation

	//TODO: Create individual animations

}