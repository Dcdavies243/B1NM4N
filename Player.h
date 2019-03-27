#pragma once

//Project Includes
#include "MovingObject.h"
#include "Framework/AnimationSystem.h"
#include "Level.h"

// Forward Declaration
class PlayerTop;
class PlayerBottom;

class Player : public MovingObject
{

public:

	Player();

	//Overriding Methods
	virtual sf::Vector2f GetPosition();
	virtual void SetPosition(float _x, float _y);
	virtual void SetPosition(sf::Vector2f _position);

	sf::FloatRect GetBounds();
	virtual void Collide(GameObject& _collider);
	virtual void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	void Input();


	//Public Player Methods
	//virtual void Collide(GameObject& _collider);
	bool HasFan();
	void CollectFan();
	void CollectTreats();

	void Kill();
	void SetLevel(Level* _newLevel);
	void AdvanceLevel();


private:

	bool m_fan;
	bool m_treats;

	//Position and Offset for Body Top
	sf::Vector2f m_position;
	sf::Vector2f m_offset;

	//Level
	Level* m_level;

	//Body Parts
	PlayerTop* m_top;
	PlayerBottom* m_bottom;

	//Bounding Boxes
	sf::FloatRect bb_top;
	sf::FloatRect bb_bottom;

	//TODO: AnimationSystem

};
