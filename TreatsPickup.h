#pragma once

// Project Includes
#include "Pickup.h"

class TreatsPickup : public Pickup
{
public:
	TreatsPickup();

private:

	// Overriding Methods
	virtual void OnPickup(Player& _player);
};
