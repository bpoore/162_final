/*********************************************************************
** Author: Elizabeth Poore
** Date: June 1, 2015
** Description: Room.hpp is the Room class specification file
*********************************************************************/
#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <vector>

class Room
{
	protected:
	std::string roomName, roomType;
	std::vector<std::string> objects;
	Room *north, *east, *south, *west;
	bool boobieTrapped, vaultOpen;
	
	public:
	Room(); 
	virtual ~Room() = 0;
	void setNorth(Room *);
	void setEast(Room *);
	void setSouth(Room *);
	void setWest(Room *);
	virtual void entranceText() = 0;
	Room* getNorth();
	Room* getEast();
	Room* getSouth();
	Room* getWest();
	std::string getName();
	std::string getRoomType();
	bool getBoobieTrapped();
	bool getVaultOpen();
	virtual int numLostTurns();
	void viewObjects();
	int numObjects();
	std::string removeObject(int);
	void addObject(std::string);
	bool objectInRoom();
};
#endif



