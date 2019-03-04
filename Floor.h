#pragma once

//Project Includes
#include "Framework/SpriteObject.h"

class Floor : public SpriteObject
{
public:
	Floor();

	//Inherited Methods
	virtual void Collide(GameObject& _collider);
};
