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
	, m_direction ()
	, m_magnitude()
	, m_blocked(false)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/PixelDog.fw.png"));

	//Set Origin
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
}

void Dog::Collide(GameObject& _collider)
{
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
		if (m_position.x < (castPlayer->GetTreatLocation().x + 300) && m_position.x > castPlayer->GetTreatLocation().x || m_position.x > (castPlayer->GetTreatLocation().x - 300) && m_position.x < castPlayer->GetTreatLocation().x && !m_blocked)
		{
			m_direction = (castPlayer->GetTreatLocation() - m_position);

			SetPosition(m_position.x + (m_normalised.x * speed), m_position.y);
		}
	}
	else
	{
		if (m_position.x < (m_playerPos.x + 300) && m_position.x > m_playerPos.x || m_position.x > (m_playerPos.x - 300) && m_position.x < m_playerPos.x && !m_blocked)
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

