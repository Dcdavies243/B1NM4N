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
	virtual void OnPickup(Player& _player);

	//Class Methods
	void SetSprite(int _currentLevel);


	AnimationSystem m_animationSystem;


};
