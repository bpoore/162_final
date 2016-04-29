/*********************************************************************
** Author: Elizabeth Poore
** Date: June 1, 2015
** Description: GameWorld.hpp is the GameWorld class specification file
*********************************************************************/
#ifndef GAMEWORLD_HPP
#define GAMEWORLD_HPP

#include <string>
#include <vector>

#include "Room.hpp"

class GameWorld
{
	protected:
	std::vector<Room *> gameRooms;
	std::vector<std::string> playerObjects;
	Room *currentRoom;
	int remainingTurns;
	bool canAdd, gameWon;

	public:
	GameWorld();
	~GameWorld();
	void addRoom(Room *);
	void setCurrentRoom(Room *);
	Room* getCurrentRoom();
	void decrementTurns();
	int getRemainingTurns();
	void addObject(std::string);
	int numObjects();
	bool canAddObject();
	std::string getObject(int);
	void removeObject(int);
	void viewItems();
	bool objectOnHand();
	void endOfTurn();
	bool playerWins();
	bool inPlay();
};

#endif






