//Project Includes
#include "Framework/AssetManager.h"
#include "B1NM3N.h"

//Constants
#define SPEED 200.0f

B1NM3N::B1NM3N()
	: MovingObject() //Initialise base class
	, m_startPosition()
	, m_endPosition()
	, m_position()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/GroundPlacehold.png"));
}

void B1NM3N::Update(sf::Time _frameTime)
{
	if (m_position != m_endPosition)
	{

	}
}