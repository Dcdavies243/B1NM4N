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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_velocity.x = -SPEED;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_velocity.x = SPEED;
	}




	//TODO: Create gravity effect


	//Call the update function manually on the parent class
	//This actually moves the character
	MovingObject::Update(_frameTime);
	//TODO: Process animations

}

sf::Vector2f Player::GetPosition()
{
	return m_bottom->GetPosition();
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

void Player::CollideWall()
{
	
	m_sprite.setPosition(m_previousPosition);

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