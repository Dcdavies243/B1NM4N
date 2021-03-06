#pragma once

//Project Includes
#include "MovingObject.h"
#include "Framework/AnimationSystem.h"
#include "Level.h"


//Forward Declaration
class Player;

class Crowd : public MovingObject
{

public:
	Crowd();

	//Overriding Methods
	void Update(sf::Time _frameTime);
	virtual void SetPosition(float _x, float _y);
	virtual void SetPosition(sf::Vector2f _position);

	//Class Methods
	virtual void MoveEnemy();
	virtual void SetTarget(Player* _castPlayer);
	virtual void Kill();


private:

	Player* castPlayer;


	sf::Vector2f m_position;
	sf::Vector2f m_playerPos;
	sf::Vector2f m_targetPos;

	sf::Vector2f m_direction;
	sf::Vector2f m_normalised;

	bool m_moving;

	float m_magnitude;
	float speed;
	float factor = 0.f;

};