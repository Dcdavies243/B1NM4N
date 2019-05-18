// Project Includes
#include "LevelChanger.h"
#include "Framework/AssetManager.h"

LevelChanger::LevelChanger()
	: Pickup()
	, m_animationSystem()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/LevelTransitionItem1.png"));

	// TODO: Set up the animation


}

void LevelChanger::Update(sf::Time _frameTime)
{
	m_animationSystem.Update(_frameTime);
}


void LevelChanger::OnPickup(Player& _player)
{
	_player.AdvanceLevel();
}