#include "Framework/AssetManager.h"
#include "FanTarget.h"
#include "FanTool.h"

//Constants
#define SPEED 200.0f

FanTarget::FanTarget()
	: SpriteObject() //Initialise base class
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Level1FanTarget.png"));


}

void FanTarget::Remove()
{
	//Delete instance of FanTarget
	m_active = false;

}