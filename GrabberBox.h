#pragma once

//Project Includes
#include "Framework/SpriteObject.h"
#include "Framework/AnimationSystem.h"
#include "Player.h"

class GrabberBox : public SpriteObject
{
public:

	GrabberBox();

	//Overriding Methods
	void SetSprite(int _currentLevel);

private:

	//TODO: AnimationSystem


};
