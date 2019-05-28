#pragma once

//Project Includes
#include "MovingObject.h"
#include "Framework/AnimationSystem.h"
#include "Level.h"


//Forward Declaration
class Player;

class Gladiator : public MovingObject
{

public:
	Gladiator();

	//Overriding Methods
	void Update(sf::Time _frameTime);

	//Class Methods
	virtual void SetTarget(Player* _castPlayer);
	virtual void Kill();


private:

	Player* castPlayer;

	sf::Vector2f m_position;
	sf::Vector2f m_playerPos;
	sf::Vector2f m_treatPos;

	sf::Vector2f m_direction;
	sf::Vector2f m_normalised;
	
	bool m_blocked;

	float m_magnitude;
	float speed;
	float factor = 0.f;

};