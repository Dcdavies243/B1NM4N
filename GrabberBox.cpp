#include "Framework/AssetManager.h"
#include "Player.h"
#include "GrabberBox.h"

//Constants
#define SPEED 200.0f

GrabberBox::GrabberBox()
	: SpriteObject() //Initialise base class
{

}

void GrabberBox::SetSprite(int _currentLevel)
{
	if (_currentLevel == 1)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/Level1Grabber.png"));
	}
	else if (_currentLevel == 2)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/Level2WallLeft.png"));
	}
	else if (_currentLevel == 3)
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/Level3Grabber.png"));
	}
}