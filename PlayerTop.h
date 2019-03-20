#pragma once

//Project Includes
#include "Framework/GameObject.h"
#include "Framework/AnimationSystem.h"
#include "Player.h"

class PlayerTop : public GameObject
{
public:

	PlayerTop();

	//Overriding Methods
	virtual void SetPosition(sf::Vector2f _position);

private:

	//TODO: AnimationSystem

};