//Project Includes
#include "Player.h"
#include "PlayerTop.h"
#include "Framework/AssetManager.h"
#include "Wall.h"
#include "Floor.h"
#include "PlayerTop.h"
#include "PlayerBottom.h"
#include "FanTool.h"
#include "TreatsTool.h"
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
	, m_treatstool(nullptr)
	, m_grabbing(false)
	, m_falling()
	, fanActive(false)
	, m_offset(0, 30.0f)
	, fanOffset(55, -43)
	, treatsOffset(0, 0)
{

	m_sprite.setTexture(AssetManager::GetTexture("graphics/GroundPlacehold.png"));

	//Set up head and body
	m_top = new PlayerTop();
	m_bottom = new PlayerBottom();

	//Set up Tools/Upgrades
	m_fantool = new FanTool();
	m_treatstool = new TreatsTool();

	//TODO: Set up the animation

	//TODO: Create individual animations

}
                                                                                                                                                                                                                                                                                                                                  
//Overriding Methods
void Player::Update(sf::Time _frameTime)
{
	//Assume no keys are pressed
	m_velocity.x = 0.0f;
	m_velocity.y = SPEED;

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
		if (m_offset.y > 30)
		{
			m_offset.y = m_offset.y - (SPEED / 600);
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		fanOffset = sf::Vector2f(-35, fanOffset.y);

		m_velocity.x = -SPEED;

		flipped = true;

		treatsOffset = sf::Vector2f(0,0);
	}

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		fanOffset = sf::Vector2f(40, fanOffset.y);

		m_velocity.x = SPEED;

		flipped = false;

		treatsOffset = sf::Vector2f(0, 0);


	}

	if (m_grabbing && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_grabbing = false;
		m_offset.y = 30.0f;

		m_bottom->SetPosition(m_grabposition + sf::Vector2f(0, -50));
	}

	if (m_fan && m_offset.y == 30.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		fanActive = true;
	}
	else
	{
		fanActive = false;
	}

	if (m_treats && !treatActive && m_offset.y == 30.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{

		treatActive = true;
		treatTarget = m_bottom->GetPosition() + treatsOffset;
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
	
	if (treatActive)
	{
		m_treatstool->SetPosition(treatTarget);
	}

}

void Player::Draw(sf::RenderTarget& _target)
{
	m_top->Draw(_target);
	m_bottom->Draw(_target);

	if (flipped)
	{
		m_top->Flip();
		m_bottom->Flip();
		m_fantool->Flip();
	}
	else
	{
		m_top->Unflip();
		m_bottom->Unflip();
		m_fantool->Unflip();
	}

	if (fanActive)
	{
		m_fantool->Draw(_target);
	}

	if (treatActive)
	{
		m_treatstool->Draw(_target);
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

	sf::FloatRect topCollider = m_top->GetBounds();

	Floor* castFloor = dynamic_cast<Floor*>(&_collider);

	if (castFloor != nullptr)
	{
		//We hit a wall
		//Return to previous position outside floor bounds

		m_bottom->SetPosition(m_position.x,m_previousPosition.y);

	}

	Wall* castWall = dynamic_cast<Wall*>(&_collider);

	if (castWall != nullptr)
	{
		//We hit a wall
		//Return to previous position outside wall bounds

		m_bottom->SetPosition(m_previousPosition);

	}

	GrabberBox* castGrabberBox = dynamic_cast<GrabberBox*>(&_collider);

	if (castGrabberBox != nullptr)
	{
		//We hit a grab box

		//Set boolean to allow us to grab
		if (topCollider.intersects(castGrabberBox->GetBounds()))
		{
			m_grabbing = true;
			m_grabposition = castGrabberBox->GetPosition();
		}
		else
		{
			m_grabbing = false;
			m_grabposition = m_bottom->GetPosition();
		}

		m_bottom->SetPosition(m_position.x, m_previousPosition.y);

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

bool Player::HasTreats()
{
	return m_treats;
}

void Player::CollectTreats()
{
	m_treats = true;
}

void Player::UseFan()
{
	fanActive = true;
}

void Player::UseTreat()
{
	treatActive = true;
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