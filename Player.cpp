//Project Includes
#include "Player.h"
#include "PlayerTop.h"
#include "Framework/AssetManager.h"
#include "Wall.h"
#include "WallRight.h"
#include "Floor.h"
#include "StoneFloor.h"
#include "PlayerTop.h"
#include "PlayerBottom.h"
#include "FanTool.h"
#include "TreatsTool.h"
#include "B1NM3N.h"
#include "Dog.h"
#include "Crowd.h"
#include "GrabberBox.h"
#include "FanTarget.h"
#include "LevelChanger.h"



//Constants
#define SPEED 150.0f


Player::Player()
	: MovingObject() //Initialise base class
	, m_level(nullptr)
	, m_top(nullptr)
	, m_bottom(nullptr)
	, m_fantool(nullptr)
	, m_treatstool(nullptr)
	, m_grabbing(false)
	, m_falling()
	, m_fallSpeed(0.0f)
	, m_treatSpeedX(0.0f)
	, m_treatSpeedY(0.0f)
	, fanActive(false)
	, m_offset(0, 30.0f)
	, fanOffset(0, 0)
	, treatsOffset(0, 0)
{

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
	m_velocity.y = m_fallSpeed;

	//Run Input Function
	Input();

	//Gravity effect
	m_fallSpeed += (125.0f * (3.0f * _frameTime.asSeconds()));


	//Kill Z
	if (m_position.y >= 1500)
	{
		m_fallSpeed = 0.0f;
		Kill();
	}



	topPositionPrev = m_top->GetPosition();

	//Update tools for animation
	m_fantool->Update(_frameTime);
	m_bottom->Update(_frameTime);

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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (m_offset.y > 30)
		{
			m_offset.y = m_offset.y - (SPEED / 600);
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		fanOffset = sf::Vector2f(-35, fanOffset.y);

		m_velocity.x = -SPEED;

		flipped = true;

		treatsOffset = sf::Vector2f(-250, -25);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		fanOffset = sf::Vector2f(400, fanOffset.y);

		m_velocity.x = SPEED;

		flipped = false;

		treatsOffset = sf::Vector2f(250, -25);

	}

	if (m_fan && sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		m_fanSelect = true;
		m_treatSelect = false;
	}
	else if (m_treats && sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		m_treatSelect = true;
		m_fanSelect = false;
	}



	if (m_grabbing && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_grabbing = false;
		m_offset.y = 30.0f;

		m_bottom->SetPosition(m_grabposition + sf::Vector2f(0, -50));
	}
	else if (!m_grabbing && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_bottom->SetPosition(m_position);
	}

	if (m_fan && m_offset.y == 30.0f && m_fanSelect && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		fanActive = true;
	}
	else
	{
		fanActive = false;
	}

	if (m_treats && !treatActive && m_offset.y == 30.0f && m_treatSelect && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{

		treatActive = true;
		treatTarget = m_bottom->GetPosition() + treatsOffset;
	}

}

bool Player::GetTreatActive()
{
	return treatActive;
}

sf::Vector2f Player::GetTreatLocation()
{
	return m_treatstool->GetPosition();
}

sf::Vector2f Player::GetPosition()
{
	return m_bottom->GetPosition();
}

void Player::SetPosition(float _x, float _y)
{
	SetPosition(sf::Vector2f(_x, _y));
}

void Player::SetPosition(sf::Vector2f _position)
{

	m_position = _position;
	m_top->SetPosition(_position - m_offset);
	m_bottom->SetPosition(_position);

	if (!flipped)
		m_fantool->SetPosition(_position + sf::Vector2f(16, -15));
	if (flipped)
		m_fantool->SetPosition(_position + sf::Vector2f(-16, -15));


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
	topCollider = m_top->GetBounds();

	treatCollider = m_treatstool->GetBounds();

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
		//Return to previous position outside floor bounds

		m_fallSpeed = 0.0f;

		if (topCollider.intersects(castFloor->GetBounds()))
		{
			m_top->SetPosition(m_position.x, topPositionPrev.y);
		}
	}

	StoneFloor* castStoneFloor = dynamic_cast<StoneFloor*>(&_collider);

	if (castStoneFloor != nullptr)
	{
		//We hit a wall
		//Return to previous position outside floor bounds

		m_fallSpeed = 0.0f;

		if (topCollider.intersects(castStoneFloor->GetBounds()))
		{
			m_top->SetPosition(m_position.x, topPositionPrev.y);
		}
	}


	Wall* castWall = dynamic_cast<Wall*>(&_collider);
	WallRight* castWallRight = dynamic_cast<WallRight*>(&_collider);

	if (castWall != nullptr || castWallRight != nullptr)
	{
		//We hit a wall
		//Return to previous position outside wall bounds

		m_bottom->SetPosition(m_previousPosition.x, m_position.y);

	}

	GrabberBox* castGrabberBox = dynamic_cast<GrabberBox*>(&_collider);

	if (castGrabberBox != nullptr)
	{
		//We hit a grab box

		//Set boolean to allow us to grab
		if (topCollider.intersects(castGrabberBox->GetBounds()))
		{
			m_bottom->SetPosition(m_previousPosition.x, m_position.y);
			m_top->SetPosition(m_position.x, topPositionPrev.y);
			m_grabbing = true;
			m_grabposition = castGrabberBox->GetPosition();
		}
		else
		{
			m_grabbing = false;
			m_grabposition = m_bottom->GetPosition();
		}

		m_fallSpeed = 0.0f;

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

	Dog* castDog = dynamic_cast<Dog*>(&_collider);

	Crowd* castCrowd = dynamic_cast<Crowd*>(&_collider);

	if (castB1NM3N != nullptr)
	{
		//We hit an enemy B1NM4N
		//Kill player, reset level

		Kill();

	}
	else if (castDog != nullptr)
	{
		//We hit an enemy B1NM4N
		//Kill player, reset level

		Kill();

	}
	else if (castCrowd != nullptr)
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

bool Player::ToolSelectFan()
{
	return m_fanSelect;
}

bool Player::ToolSelectTreats()
{
	return m_treatSelect;
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