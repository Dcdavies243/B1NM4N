// Project Includes
#include "LevelChanger.h"
#include "Framework/AssetManager.h"

LevelChanger::LevelChanger()
	: Pickup()
	, m_animationSystem()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/LevelTransitionItem1.png"));

}

void LevelChanger::SetSprite(int _currentLevel)
{
	//Set sprite dependent on level
	if (_currentLevel == 1)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/LevelTransitionItem1.png"));
	}
	if (_currentLevel == 2)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/LevelTransitionItem2.png"));
	}
	if (_currentLevel == 3)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/LevelTransitionItem3.png"));
	}
}

void LevelChanger::OnPickup(Player& _player)
{
	//Run the players AdvanceLevel function when player collides
	_player.AdvanceLevel();
}