#pragma once

//Project Includes
#include "Framework/SpriteObject.h"

//Forward Declerations
class Player;

class UI : public SpriteObject
{
public:
	UI();

	//Overridding functions
	virtual void Update(sf::Time _frameTime);
	
	//Class functions
	void SetSprite();
	void SetPlayer(Player* _player);

private:

	Player* m_player;
};

