#include "Framework/AssetManager.h"
#include "FanTool.h"

//Constants
#define SPEED 200.0f

FanTool::FanTool()
	: SpriteObject() //Initialise base class
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/FanItemTool/sprite_0.png"));

	// Set up the animation
	m_animationSystem.SetSprite(m_sprite);

	// Create indvidual animations
	Animation& activeTool = m_animationSystem.CreateAnimation("activeTool");

	activeTool.AddFrame(AssetManager::GetTexture("graphics/FanItemTool/sprite_1.png"));
	activeTool.AddFrame(AssetManager::GetTexture("graphics/FanItemTool/sprite_2.png"));
	activeTool.AddFrame(AssetManager::GetTexture("graphics/FanItemTool/sprite_3.png"));
	activeTool.AddFrame(AssetManager::GetTexture("graphics/FanItemTool/sprite_4.png"));
	activeTool.AddFrame(AssetManager::GetTexture("graphics/FanItemTool/sprite_5.png"));
	activeTool.AddFrame(AssetManager::GetTexture("graphics/FanItemTool/sprite_6.png"));
	activeTool.AddFrame(AssetManager::GetTexture("graphics/FanItemTool/sprite_7.png"));
	activeTool.AddFrame(AssetManager::GetTexture("graphics/FanItemTool/sprite_8.png"));

	activeTool.SetPlayBackSpeed(20);
	activeTool.SetLoop(true);

	m_animationSystem.Play("activeTool");

	//Set Origin
	m_sprite.setOrigin(0, m_sprite.getGlobalBounds().height / 2);
}

void FanTool::Update(sf::Time _frameTime)
{
	m_animationSystem.Update(_frameTime);
}

void FanTool::RunAnimation()
{
	//m_animationSystem.Play("activeTool");
}

void FanTool::Flip()
{

	m_sprite.setScale(-1.f, 1.f);
}

void FanTool::Unflip()
{

	m_sprite.setScale(1.f, 1.f);
}