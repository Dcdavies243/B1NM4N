//Project Includes
#include "UI.h"
#include "Framework/AssetManager.h"

UI::UI()
	: SpriteObject() //Initialise parent class

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/UI_Fan.png"));
}