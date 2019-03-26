//Project Includes
#include "Player.h"
#include "PlayerTop.h"
#include "Framework/AssetManager.h"
#include "Floor.h"
#include "PlayerTop.h"
#include "PlayerBottom.h"

//Constants
#define SPEED 200.0f


Player::Player()
	: MovingObject() //Initialise base class
	, m_level(nullptr)
	, m_top(nullptr)
	, m_bottom(nullptr)
	, m_position()
	, m_offset(0, 50.0f)
{

	//TODO: Set up head and body
	m_top = new PlayerTop();
	m_bottom = new PlayerBottom();

	//TODO: Set up the animation

	//TODO: Create individual animations

}
                                                                                                                                                                                                                                                                                                                                  
//Overriding Methods
void Player::Update(sf::Time _frameTime)
{
	//Assume no keys are pressed
	m_velocity.x = 0.0f;
	m_velocity.y = 0.0f;

	Input();


	//TODO: Create gravity effect


	//Call the update function manually on the parent class
	//This actually moves the character
	MovingObject::Update(_frameTime);
	//TODO: Process animations

}

void Player::Input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (m_offset.y < 150)
		{
			m_offset.y = m_offset.y - (-SPEED / 400);
		}

		if (m_offset.y > 150)
		{
			m_offset.y = -50;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (m_offset.y > 50)
		{
			m_offset.y = m_offset.y - (SPEED / 400);
		}

		if (m_offset.y < 50)
		{
			m_offset.y = -50;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_velocity.x = -SPEED;
	}

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_velocity.x = SPEED;
	}

}

sf::Vector2f Player::GetPosition()
{
	return m_bottom->GetPosition();

	m_position = m_bottom->GetPosition();
}

void Player::SetPosition(float _x, float _y)
{
	SetPosition(sf::Vector2f(_x,_y));
}

void Player::SetPosition(sf::Vector2f _position)
{
	m_position = _position;
	m_top->SetPosition(_position - m_offset);
	m_bottom->SetPosition(_position);
}

void Player::Draw(sf::RenderTarget& _target)
{
	m_top->Draw(_target);

	m_bottom->Draw(_target);
}

void Player::Collide(GameObject& _collider)
{
	
	// Only do something if the thing
	// we touched was a wall

	// Dynamic cast the GameObjec ref
	// into a Wall pointer
	// if it succeeds, it was a wall
	Floor* floorCollider = dynamic_cast<Floor*>(&_collider);

	// If it was a wall we hit, we need to more ourselves
	// outside the wall's bounds, aka back where we were
	if (floorCollider != nullptr)
	{
		// We did hit a wall!!!

		// Return to our previous position that we just
		// moved away from this frame
		

		// clumsy - results in "sticky" walls
		// But good enough for this game
	}

}

bool Player::HasFan()
{
	return m_fan;
}

void Player::CollectFan()
{
	m_fan = true;
}

void Player::CollectTreats()
{
	m_treats = true;
}

void Player::Kill()
{
	//Reload current level

	if (m_level != nullptr)
		m_level->ReloadLevel();
}

void Player::SetLevel(Level* _newLevel)
{
	m_level = _newLevel;
}

void Player::AdvanceLevel()
{
	//advance to next level
	if (m_level != nullptr)
		m_level->LoadNextLevel();
}