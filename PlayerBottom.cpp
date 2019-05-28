#include "Player.h"
#include "Framework/AssetManager.h"
#include "Floor.h"
#include "PlayerBottom.h"

//Constants
#define SPEED 200.0f

PlayerBottom::PlayerBottom()
	: SpriteObject() //Initialise base class
{

	// Set up the animation
	m_animationSystem.SetSprite(m_sprite);

	// Create indvidual animations
	Animation& bottomMove = m_animationSystem.CreateAnimation("bottomMove");

	bottomMove.AddFrame(AssetManager::GetTexture("graphics/PlayerBottomSet/1.png"));
	bottomMove.AddFrame(AssetManager::GetTexture("graphics/PlayerBottomSet/2.png"));

	bottomMove.SetPlayBackSpeed(10);
	bottomMove.SetLoop(true);

	m_animationSystem.Play("bottomMove");

	//Set Origin
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
}

void PlayerBottom::Update(sf::Time _frameTime)
{
	m_animationSystem.Update(_frameTime);
}

void PlayerBottom::RunAnimation()
{
	m_animationSystem.Play();
}

void PlayerBottom::PauseAnimation()
{
	m_animationSystem.Pause();
}