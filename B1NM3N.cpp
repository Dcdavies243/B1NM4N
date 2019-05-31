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
	//Set Sprite
	m_sprite.setTexture(AssetManager::GetTexture("graphics/RobotEnemy.png"));

	//Set Origin
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height/ 5);

	//Set sound
	m_detectSound.setBuffer(AssetManager::GetSoundBuffer("audio/RobotSound.ogg"));
}

void B1NM3N::SetPosition(sf::Vector2f _position)
{
	//Set sprite position
	//(Used for updating sprite position for movement)
	m_sprite.setPosition(_position);
}

void B1NM3N::SetPosition(float _x, float _y)
{
	//Set sprite position
	//(Used to set sprite on grid)
	m_sprite.setPosition(_x, _y);
}

sf::FloatRect B1NM3N::GetBounds()
{
	//Get the bounds of the B1NM3N sprite
	return m_sprite.getGlobalBounds();
}

void B1NM3N::Update(sf::Time _frameTime)
{
	//Run MoveEnemy function each frame
	//(Sets the B1NM3N sprite position each frame)
	MoveEnemy(_frameTime);
}

void B1NM3N::SetPatrol()
{
	//Sets points for linear interpolation based on the specific B1NM3N object
	//(used in MoveEnemy function)
	pointA = m_sprite.getPosition() + sf::Vector2f(200, 0);
	pointB = m_sprite.getPosition();
}

void B1NM3N::MoveEnemy(sf::Time _frameTime)
{
	//Flip sprite and change direction is reaches patrol point
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

	//Run SetPosition with Interpolate function
	//(takes set points from SetPatrol function, and the factor from above)
	SetPosition(Interpolate(pointA, pointB, factor));

}


sf::Vector2f B1NM3N::Interpolate(const sf::Vector2f pointA, const sf::Vector2f pointB, float factor)
{
	//Interpolation is an estimation of a value within two known values in a sequence of values.
	//Our two known values are 

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