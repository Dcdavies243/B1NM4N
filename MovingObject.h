#pragma once

//Project Inludes
#include "Framework/SpriteObject.h"

class MovingObject : public SpriteObject
{

public:

	MovingObject();

	//Overriding Methods
	void Update(sf::Time _frameTime);

	void HandleCollision(sf::FloatRect _platform);

protected:

	sf::Vector2f m_velocity; //pixels per second
	sf::Vector2f m_previousPosition;
};
