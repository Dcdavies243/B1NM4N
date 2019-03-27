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
	virtual void SetPosition(float _x, float _y);
	virtual void SetPosition(sf::Vector2f _position);
	sf::FloatRect GetBounds();

	//Class Methods
	sf::Vector2f Interpolate(const sf::Vector2f pointA,	const sf::Vector2f pointB, float factor);
	virtual void MoveEnemy(sf::Time _frameTime);
	virtual void SetPatrol();


private:

	bool turned;

	sf::Vector2f m_position;

	float factor = 0.f;
	float speed;
	sf::Vector2f pointA;
	sf::Vector2f pointB;

};