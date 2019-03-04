// Project Includes
#include "FanPickup.h"
#include "Framework/AssetManager.h"

FanPickup::FanPickup()
	: Pickup()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/ItemPlacehold.png"));
}


void FanPickup::OnPickup(Player& _player)
{
	_player.CollectFan();
}