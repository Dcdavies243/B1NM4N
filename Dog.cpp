//Project Includes
#include "Framework/AssetManager.h"
#include "Dog.h"
#include "Player.h"


Dog::Dog()
	: MovingObject() //Initialise base class
	, m_position()
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

void Dog::Update(sf::Time _frameTime)
{
	m_position = m_sprite.getPosition();

	MoveEnemy(_frameTime);

}

void Dog::GetTarget()
{



}

void Dog::MoveEnemy(sf::Time _frameTime)
{

	

}