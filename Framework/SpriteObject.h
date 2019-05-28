#pragma once

// Project Includes
#include "GameObject.h"

class SpriteObject
	// The " : public " means this class inherits from any class names that follow
	: public GameObject
{
public:

	SpriteObject();

	// Overriding Methods
	void Draw(sf::RenderTarget& _target);
	sf::FloatRect GetBounds();
	virtual void SetPosition(sf::Vector2f _position);
	virtual void SetPosition(float _x, float _y);
	virtual sf::Vector2f GetPosition();
	

	void Flip();
	void Unflip();

protected: // This means derived/child classes can access

	bool flipped;

	sf::Sprite m_sprite;
	

};