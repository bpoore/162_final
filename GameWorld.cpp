/*********************************************************************
** Author: Elizabeth Poore
** Date: June 1, 2015
** Description: GameWorld.cpp is the GameWorld class implementation file
*********************************************************************/	
#include <iostream>

#include "GameWorld.hpp"


GameWorld::GameWorld() // Constructor initializing the number of turns allowed
{
	remainingTurns = 20;
} 

GameWorld::~GameWorld() // Destructor
{
    for(unsigned x=0; x<gameRooms.size(); x++)
    {
      	Room* tmpRoom = this->gameRooms.back();
       	this->gameRooms.pop_back();
       	delete tmpRoom;
    }
}

/*********************************************************************
**            GameWorld::addRoom
** Description: This function adds a pointer to Room object to the vector 
** of rooms making up the game word.
** Parameters: The function accepts a pointer to Room object and doesn't return 
** anything.
*********************************************************************/	
void GameWorld::addRoom(Room *r)
{
	gameRooms.push_back(r);
}


void GameWorld::setCurrentRoom(Room *r) // Set function
{
	currentRoom = r;
}

Room* GameWorld::getCurrentRoom() // Get Function
{
	return currentRoom;
}

/*********************************************************************
**            GameWorld::decrementTurns
** Description: This function determines the number of turns lost when a player
** enters a boobie trapped room.
** Parameters: None.
*********************************************************************/	
void GameWorld::decrementTurns()
{
	bool shield = false;
 
	for (unsigned x=0; x<playerObjects.size(); x++)
	{
		if (playerObjects[x] == "Shield")
		{
			shield = true;
		}
	}

	std::cout << "Rolling a 6-sided die to determine the number of turns lost" << std::endl;
	int numLost = currentRoom->numLostTurns();
	std::cout << "You rolled a " << numLost << "." << std::endl;

	if (currentRoom->getBoobieTrapped() && shield) // If the player has a shield, decrease damage 1/2
	{
		std::cout << "Your shield is providing you protection from full damage!" << std::endl;
		int half = numLost / 2;
		if (half == 0)
		{
			std::cout << "You did not experience any lost turns!" << std::endl;
		}
		else
		{
			std::cout << "You lost " << half << " turns." << std::endl;
		}
		if (remainingTurns - half > 0)
		{
			remainingTurns -= half;
		}
		else
		{
			remainingTurns = 0;
		}
	}
	else if (numLost) // If no shield, player receives full damage
	{
		if (remainingTurns - numLost > 0)
		{
			remainingTurns -= numLost;
		}
		else
		{
			remainingTurns = 0;
		}
	}
}

int GameWorld::getRemainingTurns() // Get function
{
	return remainingTurns;
}

/*********************************************************************
**            GameWorld::addObject
** Description: This function adds an item to the vector of items the player 
** has in the game currently.
** Parameters: A string representing the item name.
*********************************************************************/	
void GameWorld::addObject(std::string obj)
{		
	playerObjects.push_back(obj);
}

/*********************************************************************
**            GameWorld::canAddObject
** Description: This function determines if the player is able to pick up 
** additional items.
** Parameters: The function returns a bool. True if the player can pick up something
** fasle if the player can not. 
*********************************************************************/	
bool GameWorld::canAddObject()
{
	bool gemBag = false;

	for (unsigned x=0; x<playerObjects.size(); x++)
	{
		if (playerObjects[x] == "Bag")
		{
			gemBag = true;
		}
	}

	if (playerObjects.size() < 2 && !gemBag) // If the player doesn't have the gem bag, they can have 2 items at a time
	{
		return true;
	}
	else if (playerObjects.size() < 5 && gemBag) // If the player has the gem bag, they can have 5 items at a time (including the bag)
	{
		return true;
	}
	else // Message displayed to player if they can't pick up an item currently
	{
		std::cout << "You must remove an item before being able to pick up anything else at this item." << std::endl;
		return false;
	}
}

int GameWorld::numObjects() // Get function
{
	return playerObjects.size();
}

std::string GameWorld::getObject(int val) // Get function
{
	return playerObjects[val-1];
}

/*********************************************************************
**            GameWorld::removeObject
** Description: This function removes an object from the player's inventory.
** The user is presented with a menu of the items they have, they select the 
** number of the item in the inventory to be removed.
** Parameters: There is an input parameter of an int, representing the placement 
** in the vector of the item.
*********************************************************************/	
void GameWorld::removeObject(int val)
{
	playerObjects.erase(playerObjects.begin()+(val-1)); // val-1 so that the numbering system presented to player starts at 1
}

/*********************************************************************
**            GameWorld::viewItems
** Description: This function displays to the player the items they currently have.
** Parameters: None
*********************************************************************/	
void GameWorld::viewItems()
{
	if (playerObjects.empty())
	{
		std::cout << "\nYou currently don't have any objects." << std::endl;
	}
	else
	{
		for (unsigned x=0; x<playerObjects.size(); x++)
		{
			std::cout << "\tObject #" << x+1 << " is a " << playerObjects[x] << std::endl;
		}
	}
}

/*********************************************************************
**            GameWorld::objectOnHand
** Description: This function checks if the player has any objects in their inventory
** (to ensure the program doesn't try to call an empty vector)
** Parameters: The function returns a bool, true if there is at least one object
** in the inventory and fasle if not.
*********************************************************************/	
bool GameWorld::objectOnHand()
{
	if (!playerObjects.empty())
	{
		return true;
	}
	else
		return false;
}

/*********************************************************************
**            GameWorld::endOfTurn
** Description: This function decrements the number of remaining turns 
** available to the player by 1 when it is called.
** Parameters: None.
*********************************************************************/	
void GameWorld::endOfTurn()
{
	remainingTurns--;
}

/*********************************************************************
**            GameWorld::playerWins
** Description: This function determines if the player has won the game.
** Parameters: The function returns true if the player has won the game, 
** it returns false otherwise.
*********************************************************************/	
bool GameWorld::playerWins()
{
	int rubyCount = 0;
	int diamondCount = 0;
	int emeraldCount = 0;

	if (currentRoom->getName() == "Vault")  // If the player is in the vault
	{
		if (!playerObjects.empty())
		{
			for (unsigned x=0; x<playerObjects.size(); x++) // Count the number of each type of gem the player has
			{
				if (playerObjects[x] == "Ruby")
					rubyCount++;
				else if (playerObjects[x] == "Diamond")
					diamondCount++;
				else if (playerObjects[x] == "Emerald")
					emeraldCount++;
			}

			// If the player has at least three of one type of gem, flag set to true for winning the game
			if (rubyCount >= 3 || diamondCount >= 3 || emeraldCount >= 3) 
			{
				gameWon = true;
			}
		}	
	}	

	else
		gameWon = false;
	
	return gameWon;
}

/*********************************************************************
**            GameWorld::inPlay
** Description: This function checks to make sure the player has turns remaining.
** Parameters: The function returns true if there are remaining turns available. 
** If there are no turns remaining, the function returns false.
*********************************************************************/	
bool GameWorld::inPlay()
{
	if (remainingTurns > 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
