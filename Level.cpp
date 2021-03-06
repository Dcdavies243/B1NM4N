
//Project Includes
#include "Level.h"
#include "Background.h"
#include "Player.h"
#include "PlayerTop.h"
#include "PlayerBottom.h"
#include "Wall.h"
#include "WallRight.h"
#include "Floor.h"
#include "StoneFloor.h"
#include "FanPickup.h"
#include "TreatsPickup.h"
#include "B1NM3N.h"
#include "Crowd.h"
#include "Gladiator.h"
#include "GrabberBox.h"
#include "FanTool.h"
#include "FanTarget.h"
#include "TreatsTool.h"
#include "Dog.h"
#include "FillerBox.h"
#include "RustGirder.h"
#include "TutSign.h"
#include "TutSign2.h"
#include "TutSign3.h"
#include "Foreground.h"
#include "Background.h"
#include "LevelChanger.h"
#include "Leaves.h"
#include "UI.h"
	//Library Includes
#include <iostream>
#include <fstream>

	Level::Level()
	: m_currentLevel(0)
	, m_player(nullptr)
	, m_updateList()
	, m_WorldList()
	, m_BackgroundList()
	, m_ForegroundList()
	, m_UIList()
	, m_collisionList()
	, centre(960, 540)
	, halfSize(400, 400)
	, camera()
	, m_musicLvl1()
	, m_musicLvl2()
	, m_musicLvl3()

	//Constructor
{
	LoadLevel(1);

}

void Level::Draw(sf::RenderTarget& _target)
{
	// TODO: Draw game objects

	//Create and update camera
	_target.setView(camera);

	//Run through lists of classes and draw in order
	//Background List
	//(Is for background and decorative objects BEHIND the player)
	for (int i = 0; i < m_BackgroundList.size(); ++i)
	{
		if (m_BackgroundList[i]->IsActive())
			m_BackgroundList[i]->Draw(_target);
	}
	//World List
	//(Is for objects on the same layer as the player)
	for (int i = 0; i < m_WorldList.size(); ++i)
	{
		if (m_WorldList[i]->IsActive())
			m_WorldList[i]->Draw(_target);
	}
	//Foreground List
	//(Is for Foreground and decorative objects INFRONT of the player)
	for (int i = 0; i < m_ForegroundList.size(); ++i)
	{
		if (m_ForegroundList[i]->IsActive())
			m_ForegroundList[i]->Draw(_target);
	}
	//UI List
	//(Is for UI objects, ensures they are drawn on top of everything and never obstructed)
	for (int i = 0; i < m_UIList.size(); ++i)
	{
		if (m_UIList[i]->IsActive())
			m_UIList[i]->Draw(_target);
	}

}

void Level::Update(sf::Time _frameTime)
{

	// Update all game objects
	// Updates World List
	for (int i = 0; i < m_WorldList.size(); ++i)
	{
		if (m_WorldList[i]->IsActive())
			m_WorldList[i]->Update(_frameTime);
	}

	//Updates UI List
	for (int i = 0; i < m_UIList.size(); ++i)
	{
		if (m_UIList[i]->IsActive())
			m_UIList[i]->Update(_frameTime);
	
	}
	// Updates Collision List
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


	// Draw game world to the window
	if (m_player->GetPosition().y < 1600)
	{
		camera.setCenter(m_player->GetPosition().x, m_player->GetPosition().y - 200);
	}

	// Stop camera if player hits Kill Z
	if (m_player->GetPosition().y == 1600)
	{
		camera.setCenter(m_player->GetPosition().x, 1150);
	}
	//Set Size of camera
	camera.setSize(sf::Vector2f(1920, 1080));
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
	m_BackgroundList.clear();
	m_WorldList.clear();
	m_ForegroundList.clear();
	m_UIList.clear();
	m_collisionList.clear();

	//Set the current Level
	m_currentLevel = _leveltoLoad;

	//Load in Music
	m_musicLvl1.openFromFile("audio/CreakingMetalSounscape.ogg");
	m_musicLvl1.setLoop(true);

	m_musicLvl2.openFromFile("audio/Level2Music.ogg");
	m_musicLvl2.setLoop(true);

	m_musicLvl3.openFromFile("audio/Level3Music.ogg");
	m_musicLvl3.setLoop(true);

	//Play music based on level
	//Level 1
	if (m_currentLevel == 1)
	{
		m_musicLvl1.play();
	}
	//Level 2
	else if (m_currentLevel == 2)
	{
		m_musicLvl1.stop();
		m_musicLvl2.play();
	}
	//Level 3
	else if (m_currentLevel == 3)
	{
		m_musicLvl2.stop();
		m_musicLvl3.play();
	}

	

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

	TreatsTool* aTreat = new TreatsTool();
	m_treat = aTreat;

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
		///////////////////////////////////////////////////////////
		////              Player and Enemy Sprites            /////
		////                                                  /////
		///////////////////////////////////////////////////////////

		// Load player into Level at position on Text File
		else if (ch == 'P')
		{
			aPlayer->SetPosition(x, y);
			aPlayer->SetLevel(this);
			m_updateList.push_back(aPlayer);
			m_WorldList.push_back(aPlayer);

			//Set tools available based on level
			//If on Level 2
			if (m_currentLevel == 2)
			{
				//Player already has fan tool
				aPlayer->CollectFan();
			}
			//If on Level 3
			if (m_currentLevel == 3)
			{
				//Player already has fan and treats tool
				aPlayer->CollectFan();
				aPlayer->CollectTreats();
			}
		}
		// Load Dog into Level at position on Text File
		else if (ch == 'D')
		{
			Dog* aDog = new Dog();
			aDog->SetPosition(x, y);
			aDog->SetTarget(aPlayer);
			m_updateList.push_back(aDog);
			m_WorldList.push_back(aDog);
			m_collisionList.push_back(std::make_pair(aPlayer, aDog));
			m_collisionList.push_back(std::make_pair(aTreat, aDog));
		}
		// Load B1NM3N into Level at position on Text File
		else if (ch == 'B')
		{
			B1NM3N* aB1NM3N = new B1NM3N();
			aB1NM3N->SetPosition(x, y);
			aB1NM3N->SetPatrol();
			m_updateList.push_back(aB1NM3N);
			m_WorldList.push_back(aB1NM3N);
			m_collisionList.push_back(std::make_pair(aPlayer, aB1NM3N));
		}
		// Load Crowd into Level at position on Text File
		else if (ch == 'C')
		{
			Crowd* aCrowd = new Crowd();
			aCrowd->SetPosition(x, y);
			aCrowd->SetTarget(aPlayer);
			m_updateList.push_back(aCrowd);
			m_WorldList.push_back(aCrowd);
			m_collisionList.push_back(std::make_pair(aPlayer, aCrowd));
		}
		// Load Gladiator into Level at position on Text File
		else if (ch == 'V')
		{
			Gladiator* aGladiator = new Gladiator();
			aGladiator->SetPosition(x, y);
			aGladiator->SetTarget(aPlayer);
			m_updateList.push_back(aGladiator);
			m_WorldList.push_back(aGladiator);
			m_collisionList.push_back(std::make_pair(aPlayer, aGladiator));
		}
		///////////////////////////////////////////////////////////
		////                   Level Sprites                  /////
		////    May change, at moment seperate for levels     /////
		///////////////////////////////////////////////////////////

		// Load Floor into Level at position on Text File
		else if (ch == 'F')
		{
			Floor* aFloor = new Floor();
			aFloor->SetPosition(x, y);
			aFloor->SetSprite(m_currentLevel);
			m_updateList.push_back(aFloor);
			m_WorldList.push_back(aFloor);
			m_collisionList.push_back(std::make_pair(aPlayer, aFloor));
		}
		// Load StoneFloor into Level at position on Text File
		else if (ch == 'S')
		{
			StoneFloor* aStoneFloor = new StoneFloor();
			aStoneFloor->SetPosition(x, y);
			m_updateList.push_back(aStoneFloor);
			m_WorldList.push_back(aStoneFloor);
			m_collisionList.push_back(std::make_pair(aPlayer, aStoneFloor));
		}
		// Load Wall into Level at position on Text File
		else if (ch == 'w')
		{
			Wall* aWall = new Wall();
			aWall->SetPosition(x, y);
			aWall->SetSprite(m_currentLevel);
			m_updateList.push_back(aWall);
			m_WorldList.push_back(aWall);
			m_collisionList.push_back(std::make_pair(aPlayer, aWall));
		}
		// Load WallRight into Level at position on Text File
		else if (ch == 'W')
		{
			WallRight* aWallRight = new WallRight();
			aWallRight->SetPosition(x, y);
			aWallRight->SetSprite(m_currentLevel);
			m_updateList.push_back(aWallRight);
			m_WorldList.push_back(aWallRight);
			m_collisionList.push_back(std::make_pair(aPlayer, aWallRight));
		}
		// Load GrabberBox into Level at position on Text File
		else if (ch == 'G')
		{
			GrabberBox* aGrabberBox = new GrabberBox();
			aGrabberBox->SetPosition(x, y);
			aGrabberBox->SetSprite(m_currentLevel);
			m_updateList.push_back(aGrabberBox);
			m_WorldList.push_back(aGrabberBox);
			m_collisionList.push_back(std::make_pair(aPlayer, aGrabberBox));
		}
		// Load FanPickup into Level at position on Text File
		else if (ch == 'I')
		{
			FanPickup* aFanPickup = new FanPickup();
			aFanPickup->SetPosition(x, y);
			m_updateList.push_back(aFanPickup);
			m_WorldList.push_back(aFanPickup);
			m_collisionList.push_back(std::make_pair(aFanPickup, aPlayer));
		}
		// Load TreatsPickup into Level at position on Text File
		else if (ch == 'O')
		{
			TreatsPickup* aTreatPickup = new TreatsPickup();
			aTreatPickup->SetPosition(x, y);
			m_updateList.push_back(aTreatPickup);
			m_WorldList.push_back(aTreatPickup);
			m_collisionList.push_back(std::make_pair(aTreatPickup, aPlayer));
		}
		else if (ch == 'R')
		{
			FanTarget* aFanTarget = new FanTarget();
			aFanTarget->SetPosition(x, y);
			m_updateList.push_back(aFanTarget);
			m_WorldList.push_back(aFanTarget);
			m_collisionList.push_back(std::make_pair(aPlayer, aFanTarget));
		}
		else if (ch == '+')
		{
			LevelChanger* aLevelChanger = new LevelChanger();
			aLevelChanger->SetPosition(x, y);
			m_updateList.push_back(aLevelChanger);
			m_WorldList.push_back(aLevelChanger);
			m_collisionList.push_back(std::make_pair(aLevelChanger, aPlayer));
		}

		///////////////////////////////////////////////////////////
		////                Background List                 ///////
		///////////////////////////////////////////////////////////

		else if (ch == '!')
		{
			Background* aBackground = new Background();
			aBackground->SetPosition(x, y);
			aBackground->SetSprite(m_currentLevel);
			m_BackgroundList.push_back(aBackground);
		}
		else if (ch == '*')
		{
			FillerBox* aFillerBox = new FillerBox();
			aFillerBox->SetPosition(x, y);
			m_BackgroundList.push_back(aFillerBox);
		}
		else if (ch == '^')
		{
			RustGirder* aRustGirder = new RustGirder();
			aRustGirder->SetPosition(x, y);
			aRustGirder->SetSprite(m_currentLevel);
			m_BackgroundList.push_back(aRustGirder);
		}
		else if (ch == '@')
		{
			TutSign* aTutSign = new TutSign();
			aTutSign->SetPosition(x, y);
			m_BackgroundList.push_back(aTutSign);
		}
		else if (ch == '~')
		{
			TutSign2* aTutSign2 = new TutSign2();
			aTutSign2->SetPosition(x, y);
			m_BackgroundList.push_back(aTutSign2);
		}
		else if (ch == '?')
		{
			TutSign3* aTutSign3 = new TutSign3();
			aTutSign3->SetPosition(x, y);
			m_BackgroundList.push_back(aTutSign3);
		}
		///////////////////////////////////////////////////////////
		////                Foreground List                 ///////
		///////////////////////////////////////////////////////////
		else if (ch == '$')
		{
			Foreground* aForeground = new Foreground();
			aForeground->SetPosition(x, y);
			m_ForegroundList.push_back(aForeground);
		}
		else if (ch == '#')
		{
		Leaves* aLeaves = new Leaves();
		aLeaves->SetPosition(x, y);
		m_ForegroundList.push_back(aLeaves);
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

	UI* aUI = new UI();
	aUI->SetPlayer(aPlayer);
	m_updateList.push_back(aUI);
	m_UIList.push_back(aUI);

}


void Level::ReloadLevel()
{
	LoadLevel(m_currentLevel);
}

void Level::LoadNextLevel()
{
	LoadLevel(m_currentLevel + 1);
}