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
	m_sprite.setTexture(AssetManager::GetTexture("graphics/CrowdLvl3.png"));

	//Set Origin
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 3.2);
}

void Crowd::SetPosition(sf::Vector2f _position)
{
	//Set sprite position
	//(Used for updating sprite position for movement)
	m_sprite.setPosition(_position);
}

void Crowd::SetPosition(float _x, float _y)
{
	//Set sprite position
	//(Used to set sprite on grid on Level Startup)
	m_sprite.setPosition(_x, _y);
}

void Crowd::SetTarget(Player* _castPlayer)
{
	//Create a pointer to the player in the level
	//(Used to get the players location relative to the Crowd object)
	castPlayer = _castPlayer;

}

void Crowd::Update(sf::Time _frameTime)
{
	//Get the current position of the Crowd Object
	m_position = m_sprite.getPosition();

	//Run MoveEnemy every frame
	MoveEnemy();

	//If the Crowd object is moving
	if (m_moving)
	{   
		//Set the Crowd Objects position based on a normalised vector
		SetPosition(m_position.x + (m_normalised.x * speed), m_position.y);

		//Get the direction of the Crowd Objects movement based on the target position
		//(Target position set in MoveEnemy)
		m_direction = (m_targetPos - m_position);

		//Set the magnitude of the vector
		//(Find the square root of (m_direction to the power of 2))
		m_magnitude = (sqrt(pow(m_direction.x, 2) + pow(m_direction.y, 2)));

		//Normalise the vector
		//(Divide direction by magnitude)
		m_normalised = sf::Vector2f(m_direction.x / m_magnitude, m_direction.y / m_magnitude);
	}
}

void Crowd::MoveEnemy()
{
	//Get the players position
	m_playerPos = castPlayer->GetPosition();

	//Get the target position
	m_targetPos = sf::Vector2f(m_position.x - 1500, m_position.y);

	//Make Crowd object move if the player is in range
	if (m_position.x < (m_playerPos.x + 1000) && m_position.x > m_playerPos.x)
	{
		m_moving = true;
	}

}

void Crowd::Kill()
{
	m_active = false;
}