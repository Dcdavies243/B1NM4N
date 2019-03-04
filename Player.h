#pragma once

//Project Includes
#include "MovingObject.h"
#include "Framework/AnimationSystem.h"
#include "Level.h"

class Player : public MovingObject
{

public:

	Player();

	//Overriding Methods
	void Update(sf::Time _frameTime);
	virtual void CollideWall();

	//Public Player Methods
	void Kill();
	void SetLevel(Level* _newLevel);
	void AdvanceLevel();


private:

	//TODO: AnimationSystem

	Level* m_level;

};
