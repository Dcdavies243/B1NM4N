//Project Includes
#include "Framework/AssetManager.h"
#include "Crowd.h"
#include "Player.h"


Crowd::Crowd()
	: MovingObject() //Initialise base class
	, m_position()
	, speed(0.3f)
	, m_direction()
	, m_magnitude()
	, m_moving(false)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Crowd.png"));
}

void Crowd::SetPosition(sf::Vector2f _position)
{
	m_sprite.setPosition(_position);
}

void Crowd::SetPosition(float _x, float _y)
{
	m_sprite.setPosition(_x, _y);
}

void Crowd::SetTarget(Player* _castPlayer)
{

	castPlayer = _castPlayer;

}

void Crowd::Update(sf::Time _frameTime)
{
	m_position = m_sprite.getPosition();

	MoveEnemy();


}

void Crowd::MoveEnemy()
{
	m_playerPos = castPlayer->GetPosition();


	if (m_position.x < (m_playerPos.x + 300) && m_position.x > m_playerPos.x || m_position.x > (m_playerPos.x - 300) && m_position.x < m_playerPos.x)
	{
		SetPosition(m_position.x + (m_normalised.x * speed), m_position.y);
	}

	m_direction = (m_playerPos - m_position);
	
	m_magnitude = (sqrt(pow(m_direction.x, 2) + pow(m_direction.y, 2)));

	m_normalised = sf::Vector2f(m_direction.x / m_magnitude, m_direction.y / m_magnitude);

}

void Crowd::Kill()
{
	m_active = false;
}