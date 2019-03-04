#pragma once

// Project Includes
#include "Pickup.h"

class FanPickup : public Pickup
{
public:
	FanPickup();

private:

	// Overriding Methods
	virtual void OnPickup(Player& _player);
};