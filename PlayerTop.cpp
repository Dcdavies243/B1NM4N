//Project Includes
#include "PlayerTop.h"
#include "Player.h"
#include "Framework/AssetManager.h"
#include "Floor.h"

//Constants
#define SPEED 200.0f

PlayerTop::PlayerTop()
	: SpriteObject() //Initialise base class
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/PlayerTopSet/PlayerTop.png"));

	// Set Origin
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);

	//TODO: Set up the animation

	//TODO: Create individual animations

}