//Project Includes
#include "Framework/AssetManager.h"
#include "Dog.h"
#include "Player.h"
#include "TreatsTool.h"
#include "Wall.h"
#include "WallRight.h"


Dog::Dog()
	: MovingObject() //Initialise base class
	, m_position()
	, speed(0.3f)
	, m_direction()
	, m_magnitude()
	, m_blocked(false)
{
	//Set sprite
	m_sprite.setTexture(AssetManager::GetTexture("graphics/PixelDog.png"));

	//Set Origin
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
}

void Dog::Collide(GameObject& _collider)
{
	//Create pointers to the wall classes
	Wall* castWall = dynamic_cast<Wall*>(&_collider);
	WallRight* castWallRight = dynamic_cast<WallRight*>(&_collider);

	if (castWall != nullptr || castWallRight != nullptr)
	{
		//We hit a wall
		//Return to previous position outside wall bounds

		m_blocked = true;

	}
}

void Dog::SetPosition(sf::Vector2f _position)
{
	//Set Sprite Position
	//(Used for updating sprite position for movement)
	m_sprite.setPosition(_position);
}

void Dog::SetPosition(float _x, float _y)
{
	//Set Sprite Position
	//(Used for setting sprite to grid on Level Load)
	m_sprite.setPosition(_x, _y);
}

void Dog::SetTarget(Player* _castPlayer)
{
	//Sets pointer to player
	//(Used to get player position and set up target when chasing player)
	castPlayer = _castPlayer;

}

void Dog::Update(sf::Time _frameTime)
{
	//Update the Dog objects position
	m_position = m_sprite.getPosition();

	//Run MoveEnemy Function each frame
	MoveEnemy();

}

void Dog::MoveEnemy()
{
	//Get Player Position
	//(Cast to Player Pointer and use Player's GetPosition Function)
	m_playerPos = castPlayer->GetPosition();

	//If the treat is spawned
	if (castPlayer->GetTreatActive())
	{
		//If the treat is within a certain distance of the Dog Object AND the dog is not being blocked
		if (m_position.x < (castPlayer->GetTreatLocation().x + 300) && m_position.x > castPlayer->GetTreatLocation().x || m_position.x > (castPlayer->GetTreatLocation().x - 300) && m_position.x < castPlayer->GetTreatLocation().x && !m_blocked)
		{
			//Set the movement direction towards the treat
			//(Cast to Player Pointer and use Player's GetTreatLocation Function)
			m_direction = (castPlayer->GetTreatLocation() - m_position);


			//Move in the set direction
			//(Uses normalised vector multiplied by speed, added onto the x position of the sprite each frame)
			SetPosition(m_position.x + (m_normalised.x * speed), m_position.y);
		}
	}
	else
	{
		//If the player is within a certain distance of the Dog Object AND the dog is not being blocked
		if (m_position.x < (m_playerPos.x + 300) && m_position.x > m_playerPos.x || m_position.x > (m_playerPos.x - 300) && m_position.x < m_playerPos.x && !m_blocked)
		{
			//Move in the set direction (towards player)
			//(Uses normalised vector multiplied by speed, added onto the x position of the sprite each frame)
			SetPosition(m_position.x + (m_normalised.x * speed), m_position.y);
		}

		m_direction = (m_playerPos - m_position);
	}

	//Calculate magnitude of the vector
	//(Find the square root of the direction to the power of 2)
	m_magnitude = (sqrt(pow(m_direction.x, 2) + pow(m_direction.y, 2)));

	//Calculate the normalised vector
	//(Divide the direction by the magnitude)
	m_normalised = sf::Vector2f(m_direction.x / m_magnitude, m_direction.y / m_magnitude);

}

void Dog::Kill()
{
	//Delete the Dog instance
	m_active = false;
}

