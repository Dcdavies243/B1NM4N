#pragma once

//Project Includes
#include "MovingObject.h"
#include "Framework/AnimationSystem.h"
#include "Level.h"


class Dog : public MovingObject
{

public:
	Dog();

	//Overriding Methods
	void Update(sf::Time _frameTime, GameObject& _position);
	virtual void SetPosition(float _x, float _y);
	virtual void SetPosition(sf::Vector2f _position);

	//Class Methods
	sf::Vector2f Interpolate(const sf::Vector2f pointA, const sf::Vector2f pointB, float factor);
	virtual void MoveEnemy(sf::Time _frameTime);
	sf::Vector2f FindTarget(GameObject& _position);
	virtual void SetPatrol();


private:


	sf::Vector2f m_position;
	sf::Vector2f m_playerPos;

	float speed;
	float factor = 0.f;

	sf::Vector2f pointA;
	sf::Vector2f pointB;

};
