#pragma once

// Project Includes
#include "Pickup.h"
#include "Framework/AnimationSystem.h"

class LevelChanger : public Pickup
{
public:
	LevelChanger();

private:


	// Overriding Methods
	virtual void Update(sf::Time _frameTime);
	virtual void OnPickup(Player& _player);


	AnimationSystem m_animationSystem;


};