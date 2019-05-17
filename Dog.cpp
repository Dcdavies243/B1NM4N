//Project Includes
#include "Framework/AssetManager.h"
#include "Dog.h"
#include "Player.h"
#include "TreatsTool.h"


Dog::Dog()
	: MovingObject() //Initialise base class
	, m_position()
	, speed(0.3f)
	, m_direction ()
	, m_magnitude()
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

void Dog::SetTarget(Player* _castPlayer)
{

	castPlayer = _castPlayer;

}

void Dog::Update(sf::Time _frameTime)
{
	m_position = m_sprite.getPosition();

	MoveEnemy();

}

void Dog::MoveEnemy()
{
	m_playerPos = castPlayer->GetPosition();

	if (castPlayer->GetTreatActive())
	{
		m_direction = (castPlayer->GetTreatLocation() - m_position);

		SetPosition(m_position.x + (m_normalised.x * speed), m_position.y);
	}
	else
	{
		if (m_position.x < (m_playerPos.x + 300) && m_position.x > m_playerPos.x || m_position.x > (m_playerPos.x - 300) && m_position.x < m_playerPos.x)
		{
			SetPosition(m_position.x + (m_normalised.x * speed), m_position.y);
		}

		m_direction = (m_playerPos - m_position);
	}

	m_magnitude = (sqrt(pow(m_direction.x, 2) + pow(m_direction.y, 2)));

	m_normalised = sf::Vector2f(m_direction.x / m_magnitude, m_direction.y / m_magnitude);

}

void Dog::Kill()
{
	m_active = false;
}

