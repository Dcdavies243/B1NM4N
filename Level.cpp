//Project Includes
#include "Level.h"
#include "Player.h"
#include "Floor.h"
#include "PlayerTop.h"


//Library Includes
#include <iostream>
#include <fstream>

Level::Level()
	: m_currentLevel(0)
	, m_player(nullptr)
	, m_playerTop(nullptr)
	, m_updateList()
	, m_WorldList()
	, m_UIList()
	, m_collisionList()
{
	LoadLevel(1);
}

void Level::Draw(sf::RenderTarget& _target)
{
	//Create and update camera
	sf::View camera = _target.getDefaultView();

	// Draw game world to the window
	camera.setCenter(m_player->GetPosition());

	// TODO: Draw game objects

	for (int i = 0; i < m_UIList.size(); ++i)
	{
		if (m_UIList[i]->IsActive())
			m_UIList[i]->Draw(_target);
	}

	for (int i = 0; i < m_WorldList.size(); ++i)
	{
		if (m_WorldList[i]->IsActive())
			m_WorldList[i]->Draw(_target);
	}


	// Draw UI to the window
	_target.setView(_target.getDefaultView());

}

void Level::Update(sf::Time _frameTime)
{

	// Update all game objects
	for (int i = 0; i < m_WorldList.size(); ++i)
	{
		if (m_WorldList[i]->IsActive())
			m_WorldList[i]->Update(_frameTime);
	}

	for (int i = 0; i < m_UIList.size(); ++i)
	{
		if (m_UIList[i]->IsActive())
			m_UIList[i]->Update(_frameTime);
	}

	for (int i = 0; i < m_collisionList.size(); ++i)
	{

		GameObject* handler = m_collisionList[i].first;
		GameObject* collider = m_collisionList[i].second;

		if (handler->IsActive() && collider->IsActive())
		{
			if (handler->GetBounds().intersects(collider->GetBounds()))
			{
				handler->Collide(*collider);
			}
		}
	}
}

void Level::LoadLevel(int _leveltoLoad)
{

	//Clean up the old level

	// Delete any data already in the level
	for (int i = 0; i < m_updateList.size(); ++i)
	{
		delete m_updateList[i];
	}

	//Clear out our lists
	m_updateList.clear();
	m_WorldList.clear();
	m_UIList.clear();
	m_collisionList.clear();

	//Set the current Level
	m_currentLevel = _leveltoLoad;

	//Set up the new level

	//Open our file for reading
	std::ifstream inFile;
	std::string fileName = "Levels/Level" + std::to_string(m_currentLevel) + ".txt";
	inFile.open(fileName);

	//Make sure file was open
	if (!inFile)
	{
		std::cerr << "Unable to open file" + fileName;
		exit(1); //Call system to stop program with error
	}

	//Set the starting X and Y coordinates used to position level objects
	float x = 0.0f;
	float y = 0.0f;

	//Define the spacing used for our grid
	float X_SPACE = 50.0f;
	float Y_SPACE = 50.0f;

	//Create the player first as other objects will need to reference it
	Player* aPlayer = new Player();
	m_player = aPlayer;

	PlayerTop* aPlayerTop = new PlayerTop();
	m_playerTop = aPlayerTop;

	//Read each character one by one from the file..
	char ch;

	//Each time try to read next character
	//If successful, execute body of loop
	//"noskipws" means our input from the file will include spaces

	while (inFile >> std::noskipws >> ch)
	{
		//Perform actions based on what character was read in

		if (ch == ' ')
		{
			x += X_SPACE;
		}
		else if (ch == '\n')
		{
			y += Y_SPACE;
			x = 0;
		}
		else if (ch == 'P')
		{
			aPlayer->SetPosition(x, y);
			aPlayer->SetLevel(this);
			m_updateList.push_back(aPlayer);
			m_WorldList.push_back(aPlayer);
		}
		else if (ch == 'T')
		{
			aPlayerTop->SetPosition(x, y);
			aPlayerTop->SetLevel(this);
			m_updateList.push_back(aPlayerTop);
			m_WorldList.push_back(aPlayerTop);
		}
		else if (ch == 'F')
		{
			Floor* aFloor = new Floor();
			aFloor->SetPosition(x, y);
			m_updateList.push_back(aFloor);
			m_WorldList.push_back(aFloor);
			m_collisionList.push_back(std::make_pair(aFloor, aPlayer));
			m_collisionList.push_back(std::make_pair(aFloor, aPlayerTop));
		}
		else if (ch == '-')
		{
			//Do nothing - empty space
		}
		else
		{
			std::cerr << "unrecognised character in level file" << ch;
		}
	}

	//Close the file
	inFile.close();

}

void Level::ReloadLevel()
{
	LoadLevel(m_currentLevel);
}

void Level::LoadNextLevel()
{
	LoadLevel(m_currentLevel + 1);
}