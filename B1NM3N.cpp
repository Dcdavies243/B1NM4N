//Project Includes
#include "Framework/AssetManager.h"
#include "B1NM3N.h"


//Constants
#define SPEED 200.0f

B1NM3N::B1NM3N()
	: MovingObject() //Initialise base class
	, m_position(m_sprite.getPosition())
	, pointA(m_position + sf::Vector2f(200, 0))
	, pointB(m_position)
	, X()
	, Y()
{

	m_sprite.setTexture(AssetManager::GetTexture("graphics/GroundPlacehold.png"));

}


void B1NM3N::Update(sf::Time _frameTime)
{
	
	MoveEnemy(_frameTime);

}

void B1NM3N::MoveEnemy(sf::Time _frameTime)
{
	factor += (0.1 * _frameTime.asSeconds());
	SetPosition(Interpolate(pointA, pointB, factor));
}

sf::Vector2f B1NM3N::Interpolate(const sf::Vector2f pointA, const sf::Vector2f pointB, float factor)
{
	if (factor > 1.0f)
		factor = 1.0f;

	else if (factor < 0.0f)
		factor = 0.0f;

	return pointA + (pointB - pointA) * factor;
}