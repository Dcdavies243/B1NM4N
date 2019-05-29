#pragma once

//Project Includes
#include "Framework/GameObject.h"

//Foward decleration
class Player;

class Level
{

public:
	Level();

	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);

	void LoadLevel(int _leveltoLoad);
	void ReloadLevel();
	void LoadNextLevel();

private:


	//GameObject Lists

	//Camera settings
	sf::View camera;
	sf::Vector2f centre;
	sf::Vector2f halfSize;

	int m_currentLevel;
	Player* m_player;
	GameObject* m_treat;
	GameObject* m_background;

	sf::Music m_musicLvl1;
	sf::Music m_musicLvl2;
	sf::Music m_musicLvl3;

	std::vector<GameObject*> m_updateList;
	std::vector<GameObject*> m_WorldList;
	std::vector<GameObject*> m_BackgroundList;
	std::vector<GameObject*> m_ForegroundList;
	std::vector<GameObject*> m_UIList;

	std::vector<std::pair<GameObject*, GameObject*> > m_collisionList;
};
