//Project Includes
#include "Player.h"
#include "PlayerTop.h"
#include "Framework/AssetManager.h"
#include "Floor.h"
#include "PlayerTop.h"
#include "PlayerBottom.h"
#include "FanTool.h"
#include "B1NM3N.h"
#include "GrabberBox.h"
#include "FanTarget.h"



//Constants
#define SPEED 200.0f


Player::Player()
	: MovingObject() //Initialise base class
	, m_level(nullptr)
	, m_top(nullptr)
	, m_bottom(nullptr)
	, m_fantool(nullptr)
	, m_grabbing(false)
	, m_falling(true)
	, fanActive(false)
	, m_offset(0, 50.0f)
	, fanOffset(55, -50)
{

	m_sprite.setTexture(AssetManager::GetTexture("graphics/GroundPlacehold.png"));

	//Set up head and body
	m_top = new PlayerTop();
	m_bottom = new PlayerBottom();

	//Set up Tools/Upgrades
	m_fantool = new FanTool();

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
	sf::Vector2f m_topPosition = m_top->GetPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (m_offset.y < 150)
		{
			m_offset.y = m_offset.y - (-SPEED / 600);
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (m_offset.y > 50)
		{
			m_offset.y = m_offset.y - (SPEED / 600);
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		fanOffset = sf::Vector2f(-30, fanOffset.y);

		m_velocity.x = -SPEED;
	}

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		fanOffset = sf::Vector2f(55, fanOffset.y);

		m_velocity.x = SPEED;
	}

	if (m_grabbing && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_grabbing = false;
		m_offset.y = 50;

		m_bottom->SetPosition(m_grabposition + sf::Vector2f(0, -50));
	}

	if (m_fan && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		fanActive = true;
	}
	else
	{
		fanActive = false;
	}
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

	m_fantool->SetPosition(_position + fanOffset);

}

void Player::Draw(sf::RenderTarget& _target)
{
	m_top->Draw(_target);

	m_bottom->Draw(_target);

	if (fanActive)
	{
		m_fantool->Draw(_target);
	}
}

sf::FloatRect Player::GetBounds()
{
	sf::FloatRect combinedBounds;
	combinedBounds.left = std::min(m_top->GetBounds().left, m_bottom->GetBounds().left);
	combinedBounds.top = std::min(m_top->GetBounds().top, m_bottom->GetBounds().top);

	float right = std::max(m_top->GetBounds().left + m_top->GetBounds().width, m_bottom->GetBounds().left + m_bottom->GetBounds().width);
	float bottom = std::max(m_top->GetBounds().top + m_top->GetBounds().height, m_bottom->GetBounds().top + m_bottom->GetBounds().height);

	combinedBounds.width = right - combinedBounds.left;
	combinedBounds.height = bottom - combinedBounds.top;

	return combinedBounds;
}

void Player::Collide(GameObject& _collider)
{

	Floor* castFloor = dynamic_cast<Floor*>(&_collider);

	if (castFloor != nullptr)
	{
		//We hit a wall
		//Return to previous position outside wall bounds

		m_bottom->SetPosition(m_previousPosition);

		m_falling = false;

	}

	GrabberBox* castGrabberBox = dynamic_cast<GrabberBox*>(&_collider);

	if (castGrabberBox != nullptr)
	{
		//We hit a grab box
		//Set boolean to allow us to grab

		m_grabbing = true;
		m_grabposition = castGrabberBox->GetPosition();

		m_bottom->SetPosition(m_previousPosition);

	}

	FanTarget* castFanTarget = dynamic_cast<FanTarget*>(&_collider);

	if (castFanTarget != nullptr)
	{
		m_bottom->SetPosition(m_previousPosition);
	}

	if (castFanTarget != nullptr && fanActive)
	{
		castFanTarget->Remove();
	}

	B1NM3N* castB1NM3N = dynamic_cast<B1NM3N*>(&_collider);

	if (castB1NM3N != nullptr)
	{
		//We hit an enemy B1NM4N
		//Kill player, reset level

		Kill();

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

void Player::UseFan()
{
	fanActive = true;
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