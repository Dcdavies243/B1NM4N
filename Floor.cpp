//Project Includes
#include "Floor.h"
#include "Player.h"
#include "PlayerTop.h"
#include "Framework/AssetManager.h"

Floor::Floor()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/GroundPlacehold.png"));

}

void Floor::Collide(GameObject& _collider)
{

	Player* castPlayer = dynamic_cast<Player*>(&_collider);

	//Only do something if the thing we touched was the player
	if (castPlayer != nullptr)
	{
		//We are touched by the player

		//Kill them (TODO)
		castPlayer->CollideWall();
	}

	PlayerTop* castPlayerTop = dynamic_cast<PlayerTop*>(&_collider);

}