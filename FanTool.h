#pragma once

//Project Includes
#include "Framework/SpriteObject.h"
#include "Framework/AnimationSystem.h"

class FanTool : public SpriteObject
{
public:

	FanTool();

	//Overriding Methods
	void Update(sf::Time _frameTime);

	//Class Methods
	void RunAnimation();
	void Flip();
	void Unflip();



private:

	AnimationSystem m_animationSystem;

};