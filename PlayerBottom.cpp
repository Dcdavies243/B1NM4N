#include "Player.h"
#include "Framework/AssetManager.h"
#include "Floor.h"
#include "PlayerBottom.h"

//Constants
#define SPEED 200.0f

PlayerBottom::PlayerBottom()
	: SpriteObject() //Initialise base class
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/PlayerPlacehold(B&T).png"));

	//TODO: Set up the animation

	//TODO: Create individual animations

}