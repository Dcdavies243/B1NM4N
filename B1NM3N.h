#pragma once

//Project Includes
#include "MovingObject.h"
#include "Framework/AnimationSystem.h"
#include "Level.h"

class B1NM3N : public MovingObject
{

public:
	B1NM3N();

	//Overriding Methods
	void Update(sf::Time _frameTime);


private:

	sf::Vector2f m_startPosition;
	sf::Vector2f m_endPosition;
	sf::Vector2f m_position;

};