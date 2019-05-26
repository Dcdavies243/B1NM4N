#pragma once

//Project Includes
#include "Framework/SpriteObject.h"
#include "Framework/AnimationSystem.h"
#include "Player.h"

class PlayerBottom : public SpriteObject
{
public:

	PlayerBottom();

	//Overriding Methods
	void Update(sf::Time _frameTime);


private:

	//TODO: AnimationSystem

	AnimationSystem m_animationSystem;
};
