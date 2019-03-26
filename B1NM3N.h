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

	//Class Methods
	sf::Vector2f Interpolate(const sf::Vector2f pointA,	const sf::Vector2f pointB, float factor);


private:

	sf::Time gameTime;

	sf::Vector2f m_startPosition;
	sf::Vector2f m_endPosition;
	sf::Vector2f m_position;

	float factor = 0.f;
	sf::Vector2f pointA = m_startPosition + sf::Vector2f(100, 0), pointB = m_startPosition - sf::Vector2f(100, 0);

};