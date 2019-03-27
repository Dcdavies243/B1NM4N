//Project Includes
#include "Framework/AssetManager.h"
#include "Dog.h"
#include "Player.h"


Dog::Dog()
	: MovingObject() //Initialise base class
	, m_position()
	, m_playerPos()
	, pointA()
	, pointB()
	, speed(0.3)
{

	m_sprite.setTexture(AssetManager::GetTexture("graphics/EnemyPlacehold.png"));
}

void Dog::SetPosition(sf::Vector2f _position)
{
	m_sprite.setPosition(_position);
}

void Dog::SetPosition(float _x, float _y)
{
	m_sprite.setPosition(_x, _y);
}

void Dog::Update(sf::Time _frameTime, GameObject& _position)
{
	m_position = m_sprite.getPosition();

	//FindTarget();
	MoveEnemy(_frameTime);
	FindTarget(_position);
}

void Dog::SetPatrol()
{

	pointA = m_sprite.getPosition();
	pointB = m_playerPos;

}

sf::Vector2f Dog::FindTarget(GameObject& _position)
{
	Player* playerPos = dynamic_cast<Player*>(&_position);

	m_playerPos = playerPos->GetPosition();

	return m_playerPos;
}

void Dog::MoveEnemy(sf::Time _frameTime)
{

	factor += (speed * _frameTime.asSeconds());

	SetPosition(Interpolate(pointA, pointB, factor));

}


sf::Vector2f Dog::Interpolate(const sf::Vector2f pointA, const sf::Vector2f pointB, float factor)
{

	if (factor > 1.0f)
	{
		factor = 1.0f;
	}

	else if (factor < 0.0f)
	{
		factor = 0.0f;
	}

	return pointA + (pointB - pointA) * factor;

}