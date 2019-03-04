#pragma once

//Project Includes
#include "MovingObject.h"
#include "Framework/AnimationSystem.h"
#include "Level.h"

class PlayerTop : public MovingObject
{

public:

	PlayerTop();

	//Overriding Methods
	void Update(sf::Time _frameTime);
	virtual void CollideWall();

	//Public Methods
	void Kill();
	void SetLevel(Level* _newLevel);
	void AdvanceLevel();

private:

	//TODO: AnimationSystem

	sf::Vector2f m_position;


	Level* m_level;


};