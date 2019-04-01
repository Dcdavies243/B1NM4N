#pragma once

//Project Includes
#include "Framework/SpriteObject.h"
#include "Framework/AnimationSystem.h"
#include "Player.h"

class FanTool : public SpriteObject
{
public:

	FanTool();

	//Overriding Methods

	void Flip();
	void Unflip();

private:

	//TODO: AnimationSystem

};