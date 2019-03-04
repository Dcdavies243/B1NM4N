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
	void FollowTop();

	//Public Player Methods
	bool HasFan();
	void CollectFan();
	void Kill();
	void SetLevel(Level* _newLevel);
	void AdvanceLevel();


private:

	bool m_fan;

	//TODO: AnimationSystem

	sf::Vector2f m_position;

	Level* m_level;

};
