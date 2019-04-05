#include "Framework/AssetManager.h"
#include "FanTarget.h"
#include "FanTool.h"

//Constants
#define SPEED 200.0f

FanTarget::FanTarget()
	: SpriteObject() //Initialise base class
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Level1FanTarget.png"));

	//TODO: Set up the animation

}

void FanTarget::Remove()
{
	m_active = false;
}