// Project Includes
#include "FanPickup.h"
#include "Framework/AssetManager.h"

FanPickup::FanPickup()
	: Pickup()
	, m_animationSystem()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/FanItemPickup/0.png"));

	// Set up the animation
	m_animationSystem.SetSprite(m_sprite);


	// Create indvidual animations
	Animation& idleItem = m_animationSystem.CreateAnimation("idleItem");

	idleItem.AddFrame(AssetManager::GetTexture("graphics/FanItemPickup/1.png"));
	idleItem.AddFrame(AssetManager::GetTexture("graphics/FanItemPickup/2.png"));
	idleItem.AddFrame(AssetManager::GetTexture("graphics/FanItemPickup/3.png"));
	idleItem.AddFrame(AssetManager::GetTexture("graphics/FanItemPickup/4.png"));
	idleItem.AddFrame(AssetManager::GetTexture("graphics/FanItemPickup/5.png"));
	idleItem.AddFrame(AssetManager::GetTexture("graphics/FanItemPickup/6.png"));

	idleItem.SetPlayBackSpeed(10);
	idleItem.SetLoop(true);

	m_animationSystem.Play("idleItem");
}

void FanPickup::Update(sf::Time _frameTime)
{
	//Update the animation every frame
	m_animationSystem.Update(_frameTime);
}


void FanPickup::OnPickup(Player& _player)
{
	//Run the Players CollectFan function
	_player.CollectFan();
}