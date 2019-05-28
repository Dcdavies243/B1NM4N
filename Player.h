#pragma once

//Project Includes
#include "MovingObject.h"
#include "Framework/AnimationSystem.h"
#include "Level.h"

// Forward Declaration
class PlayerTop;
class PlayerBottom;
class GrabberBox;
class FanTool;
class TreatsTool;

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
	bool GetTreatActive();
	sf::Vector2f GetTreatLocation();

	//Pickup Methods
	bool HasFan();
	void CollectFan();
	bool HasTreats();
	void CollectTreats();

	//Tool Methods
	void UseFan();
	void UseTreat();


	void Kill();
	void SetLevel(Level* _newLevel);
	void AdvanceLevel();


private:

	bool m_grabbing;
	bool m_fan;
	bool m_treats;
	bool m_falling;

	bool m_fanSelect;
	bool m_treatSelect;

	float m_fallSpeed;
	float m_treatSpeedX;
	float m_treatSpeedY;

	//Tool variables
	bool fanActive;

	bool treatActive;

	sf::Vector2f topPositionPrev;

	sf::Vector2f treatTarget;


	//Position and Offset for Body
	sf::Vector2f m_position;
	sf::Vector2f m_offset;

	//Offset for Fan
	sf::Vector2f fanOffset;

	//Target for treats
	sf::Vector2f treatsOffset;

	//Variable for grabbing position
	sf::Vector2f m_grabposition;

	//Level
	Level* m_level;

	//Colliders
	sf::FloatRect topCollider;
	sf::FloatRect treatCollider;

	//Body Parts
	PlayerTop* m_top;
	PlayerBottom* m_bottom;

	//Tool upgrades
	FanTool* m_fantool;
	TreatsTool* m_treatstool;

	//TODO: AnimationSystem

};
