/*********************************************************************
** Author: Elizabeth Poore
** Date: June 1, 2015
** Description: Room.cpp is the Room class implementation file
*********************************************************************/	
#include <iostream>

#include "Room.hpp"

Room::Room()  // Constructor
{
	setNorth(NULL);
	setEast(NULL);
	setSouth(NULL);
	setWest(NULL);
	boobieTrapped = false;
	vaultOpen = false;
}	

Room::~Room(){} // Destructor

/*********************************************************************
**         Set functions
*********************************************************************/	
void Room::setNorth(Room *n)
{
	north = n;
}

void Room::setEast(Room *e)
{
	east = e;
}

void Room::setSouth(Room *s)
{
	south = s;
}

void Room::setWest(Room *w)
{
	west = w;
}

void entranceText() {}

/*********************************************************************
**         Get functions
*********************************************************************/	
Room* Room::getNorth()
{
	return north;
}

Room* Room::getEast()
{
	return east;
}

Room* Room::getSouth()
{
	return south;
}

Room* Room::getWest()
{
	return west;
}

std::string Room::getName()
{
	return roomName;
}

std::string Room::getRoomType()
{
	return roomType;
}

bool Room::getBoobieTrapped()
{
	return boobieTrapped;
}

bool Room::getVaultOpen()
{
	return vaultOpen;
}

int Room::numObjects()
{
	return objects.size();
}

int Room::numLostTurns() // Default 0 lost turns. Used in boobie trapped room.
{
	return 0;
}


/*********************************************************************
**                      Room::viewObjects
** Description: This function displays to the screen the objects currently in 
** a given room. 
** Parameters: None.
*********************************************************************/	
void Room::viewObjects()
{	
	if (objects.empty())		
	{
		std::cout << "\nThere are no objects in the room." << std::endl;
	}
	else
	{
		std::cout << "The object(s) in this room are: " << std::endl;
		for (unsigned x=0; x<objects.size(); x++)
		{
			std::cout << "\tObject #" << x+1 << " is a " << objects[x] << std::endl;
		}
	}
}

/*********************************************************************
**                   Room::removeObject
** Description: This function removes an item from the vector of items 
** representing what's in a current room. The function is called when a player
** picks up an object. This function removes the object in question from 
** the room's inventory.
** Parameters: This function accepts and argument of an int representing the location
** in the vector the item is, it returns a string of the "object".
*********************************************************************/	
std::string Room::removeObject(int loc)
{
	std::string temp = objects[loc-1]; // loc-1 so that the player can enter a value starting at 1 rather than 0
	objects.erase(objects.begin()+(loc-1));
	return temp;
}  

/*********************************************************************
**                     Room::addObject
** Description: This function adds an item to the vector of items representing 
** what's in a current room. The function is called when a player puts an
** object down in a room, thus removing it from their inventory and adding it to the room's. 
** Parameters: This function accepts and argument a string, the obejct. The function
** doesn't return a value.
*********************************************************************/	
void Room::addObject(std::string obj)
{
	objects.push_back(obj);
}

/*********************************************************************
**                     Room::objectInRoom
** Description: This function determines if there are any objects present in 
** the room. It's purpose is to ensure the program doesn't try to work with 
** an empty vector.
** Parameters: This function has no input parameters. It returns a bool, true
** if there's at least one object in the room, false otherwise.
*********************************************************************/	
bool Room::objectInRoom()
{
	if (!objects.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}


