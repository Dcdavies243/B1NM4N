// Project Includes
#include "TreatsPickup.h"
#include "Framework/AssetManager.h"

TreatsPickup::TreatsPickup()
	: Pickup()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/ItemPlacehold.png"));
}


void TreatsPickup::OnPickup(Player& _player)
{
	_player.CollectTreats();
}