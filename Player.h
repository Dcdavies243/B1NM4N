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
	virtual void SetPosition(sf::Vector2f _position);
	virtual void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	virtual void CollideWall();

	//Public Player Methods
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

	//TODO: AnimationSystem

};
