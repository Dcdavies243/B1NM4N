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
	void Update(sf::Time _frameTime);
	virtual void SetPosition(float _x, float _y);
	virtual void SetPosition(sf::Vector2f _position);

	//Class Methods
	virtual void MoveEnemy(sf::Time _frameTime);
	virtual void GetTarget();


private:


	sf::Vector2f m_position;
	sf::Vector2f m_playerPos;

	float speed;
	float factor = 0.f;

};
