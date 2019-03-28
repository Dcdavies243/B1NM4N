#include "Player.h"
#include "Framework/AssetManager.h"
#include "Floor.h"
#include "FanTool.h"

//Constants
#define SPEED 200.0f

FanTool::FanTool()
	: SpriteObject() //Initialise base class
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/FanToolPlacehold.png"));

	//TODO: Set up the animation

	//TODO: Create individual animations

}