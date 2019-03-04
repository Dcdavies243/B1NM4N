//Project Includes
#include "PlayerTop.h"
#include "Player.h"
#include "Framework/AssetManager.h"
#include "Floor.h"

//Constants
#define SPEED 200.0f

PlayerTop::PlayerTop()
	: MovingObject() //Initialise base class
	, m_position(0.0f, 0.0f)
	, m_level(nullptr)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/PlayerPlacehold(B&T).png"));

	//TODO: Set up the animation

	//TODO: Create individual animations

}

//Overriding Methods
void PlayerTop::Update(sf::Time _frameTime)
{
	//Get current X and Y position
	m_position = m_sprite.getPosition();

	//Assume no keys are pressed
	m_velocity.x = 0.0f;
	m_velocity.y = 0.0f;



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_sprite.setPosition(m_position.x, m_position.y - 50.0f);
	}
	

	//TODO: Create gravity effect


	//Call the update function manually on the parent class
	//This actually moves the character
	MovingObject::Update(_frameTime);

	//TODO: Process animations

}

void PlayerTop::CollideWall()
{
	m_sprite.setPosition(m_previousPosition);
}

void PlayerTop::Kill()
{
	//Reload current level

	if (m_level != nullptr)
		m_level->ReloadLevel();
}

void PlayerTop::SetLevel(Level* _newLevel)
{
	m_level = _newLevel;
}

void PlayerTop::AdvanceLevel()
{
	//advance to next level
	if (m_level != nullptr)
		m_level->LoadNextLevel();
}