#include "Framework/AssetManager.h"
#include "FanTarget.h"
#include "FanTool.h"

//Constants
#define SPEED 200.0f

FanTarget::FanTarget()
	: SpriteObject() //Initialise base class
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/FanTargetPlacehold.png"));

	//TODO: Set up the animation

	//TODO: Create individual animations

}

void FanTarget::Remove()
{
	m_active = false;
}