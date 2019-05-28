//Project Includes
#include "Framework/AssetManager.h"
#include "B1NM3N.h"


//Constants
#define SPEED 200.0f

B1NM3N::B1NM3N()
	: MovingObject() //Initialise base class
	, turned(false)
	, m_position()
	, speed(0.3f)
	, pointA()
	, pointB()
{

	m_sprite.setTexture(AssetManager::GetTexture("graphics/EnemyPlacehold.png"));

	//Set Origin
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
}

void B1NM3N::SetPosition(sf::Vector2f _position)
{
	m_sprite.setPosition(_position);
}

void B1NM3N::SetPosition(float _x, float _y)
{
	m_sprite.setPosition(_x, _y);
}

sf::FloatRect B1NM3N::GetBounds()
{
	return m_sprite.getGlobalBounds();
}

void B1NM3N::Update(sf::Time _frameTime)
{
	MoveEnemy(_frameTime);
}

void B1NM3N::SetPatrol()
{
	pointA = m_sprite.getPosition() + sf::Vector2f(200, 0);
	pointB = m_sprite.getPosition();
}

void B1NM3N::MoveEnemy(sf::Time _frameTime)
{
	if (m_sprite.getPosition() == pointB)
	{
		Unflip();
		speed = -0.3;
	}
	if (m_sprite.getPosition() == pointA)
	{
		Flip();
		speed = 0.3;
	}
	factor += (speed * _frameTime.asSeconds());


	SetPosition(Interpolate(pointA, pointB, factor));

}


sf::Vector2f B1NM3N::Interpolate(const sf::Vector2f pointA, const sf::Vector2f pointB, float factor)
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