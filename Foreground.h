#pragma once

//Project Includes
#include "Framework/SpriteObject.h"

//Forward Decleration
class Player;


class Foreground : public SpriteObject
{
public:
	Foreground();


private:

	Player* castPlayer;
};