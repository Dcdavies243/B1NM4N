#include "Framework/AssetManager.h"
#include "GrabberBox.h"

//Constants
#define SPEED 200.0f

GrabberBox::GrabberBox()
	: SpriteObject() //Initialise base class
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Grabber.png"));

	//TODO: Set up the animation

	//TODO: Create individual animations

}