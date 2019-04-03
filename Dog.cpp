//Project Includes
#include "Framework/AssetManager.h"
#include "Dog.h"
#include "Player.h"


Dog::Dog()
	: MovingObject() //Initialise base class
	, m_position()
	, speed()
	, m_direction (1, 0)
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
	if (castPlayer != nullptr)
		castPlayer = _castPlayer;

}

void Dog::Update(sf::Time _frameTime)
{
	m_position = m_sprite.getPosition();

	MoveEnemy();

	m_playerPos = castPlayer->GetPosition();

	m_direction = m_playerPos;
	
}

void Dog::MoveEnemy()
{

	SetPosition((m_position.x) * m_direction.x, m_position.y);

}