#pragma once

//Project Includes
#include "Framework/SpriteObject.h"

class Wall : public SpriteObject
{
public:
	Wall();

	void SetSprite(int _currentLevel);
};
