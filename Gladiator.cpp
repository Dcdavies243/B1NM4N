//Project Includes
#include "Framework/AssetManager.h"
#include "Gladiator.h"
#include "Player.h"
#include "TreatsTool.h"
#include "Wall.h"
#include "WallRight.h"


Gladiator::Gladiator()
	: MovingObject() //Initialise base class
	, m_position()
	, speed(0.3f)
	, m_direction()
	, m_magnitude()
	, m_blocked(false)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Gladiator.png"));

	//Set Origin
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
}

void Gladiator::SetTarget(Player* _castPlayer)
{

	castPlayer = _castPlayer;

}

void Gladiator::Update(sf::Time _frameTime)
{
	m_position = m_sprite.getPosition();

	m_playerPos = castPlayer->GetPosition();

	if (m_position.x < (m_playerPos.x + 300) && m_position.x > m_playerPos.x)
	{
		Kill();
	}

}

void Gladiator::Kill()
{
	m_active = false;
}

